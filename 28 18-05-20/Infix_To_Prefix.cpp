#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '/' || c == '*')
		return 2;
	if (c == ')')
		return 3;
}

string func(string s) {
	// cam also be calculated as reverse of s and its postefix and then its reverse

	int n = s.length();
	stack<char> operators;
	stack<string> operand;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			string temp = "";
			temp += s[i];
			operand.push(temp);
		}
		else if (s[i] == '(')
			operators.push(s[i]);
		else if (s[i] == ')') {
			while (operators.top() != '(') {
				char temp = operators.top();
				operators.pop();
				string pop1 = operand.top();
				operand.pop();
				string pop2 = operand.top();
				operand.pop();
				string result = temp + pop2 + pop1;
				operand.push(result);
			}
			operators.pop();
		}
		else {
			while (!operators.empty() && priority(operators.top()) >= priority(s[i]) && operators.top() != '(') {
				char temp = operators.top();
				operators.pop();
				string pop1 = operand.top();
				operand.pop();
				string pop2 = operand.top();
				operand.pop();
				string result = temp + pop2 + pop1;
				operand.push(result);
			}
			operators.push(s[i]);
		}
	}
	while (!operators.empty()) {
		char temp = operators.top();
		operators.pop();
		string pop1 = operand.top();
		operand.pop();
		string pop2 = operand.top();
		operand.pop();
		string result = temp + pop2 + pop1;
		operand.push(result);
	}
	return operand.top();
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << func(s) << endl;
	}
	return 0;
}