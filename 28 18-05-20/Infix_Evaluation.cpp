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

int operation(char c, int a, int b) {
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/')
		return a / b;
}

int func(string s) {
	int n = s.length();
	stack<char> operators;
	stack<int> operand;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			operand.push(s[i] - '0');
		else if (s[i] == '(')
			operators.push(s[i]);
		else if (s[i] == ')') {
			while (operators.top() != '(') {
				char temp = operators.top();
				operators.pop();
				int b = operand.top();
				operand.pop();
				int a = operand.top();
				operand.pop();
				int result = operation(temp, a, b);
				operand.push(result);
			}
			operators.pop();
		}
		else {
			while (!operators.empty() && priority(operators.top()) >= priority(s[i]) && operators.top() != '(') {
				char temp = operators.top();
				operators.pop();
				int b = operand.top();
				operand.pop();
				int a = operand.top();
				operand.pop();
				int result = operation(temp, a, b);
				operand.push(result);
			}
			operators.push(s[i]);
		}
	}
	while (!operators.empty()) {
		char temp = operators.top();
		operators.pop();
		int b = operand.top();
		operand.pop();
		int a = operand.top();
		operand.pop();
		int result = operation(temp, a, b);
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