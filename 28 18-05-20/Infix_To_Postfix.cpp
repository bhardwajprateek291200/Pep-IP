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
	int n = s.length();
	stack<char> operators;
	string ans = "";
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			ans += s[i];
		else if (s[i] == '(')
			operators.push(s[i]);
		else if (s[i] == ')') {
			while (operators.top() != '(') {
				char temp = operators.top();
				operators.pop();
				ans += temp;
			}
			operators.pop();
		}
		else {
			while (!operators.empty() && priority(operators.top()) >= priority(s[i]) && operators.top() != '(') {
				char temp = operators.top();
				operators.pop();
				ans += temp;
			}
			operators.push(s[i]);
		}
	}
	while (!operators.empty()) {
		char temp = operators.top();
		operators.pop();
		ans += temp;
	}
	return ans;
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