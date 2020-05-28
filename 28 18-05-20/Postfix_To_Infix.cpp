#include <bits/stdc++.h>
using namespace std;

string func(string s) {
	int n = s.length();
	stack<string> operand;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			string temp = "";
			temp += s[i];
			operand.push(temp);
		}
		else {
			char temp = s[i];
			string pop1 = operand.top();
			operand.pop();
			string pop2 = operand.top();
			operand.pop();
			string result = '(' + pop2 + temp + pop1 + ')';
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