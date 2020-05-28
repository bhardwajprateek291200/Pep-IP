#include <bits/stdc++.h>
using namespace std;

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
	stack<int> operand;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			operand.push(s[i] - '0');
		else {
			char temp = s[i];
			int pop1 = operand.top();
			operand.pop();
			int pop2 = operand.top();
			operand.pop();
			int result = operation(temp, pop2, pop1);
			operand.push(result);
		}
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