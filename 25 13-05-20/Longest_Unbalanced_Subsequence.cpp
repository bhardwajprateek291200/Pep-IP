#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
	int n = s.length();
	stack<char> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
		else {
			if (st.empty())
				return false;
			if (s[i] == ')' && st.top() != '(')
				return false;
			if (s[i] == '}' && st.top() != '{')
				return false;
			if (s[i] == ']' && st.top() != '[')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

int func(string s) {
	if (isValid(s))
		return s.length() - 1;
	else
		return s.length();
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