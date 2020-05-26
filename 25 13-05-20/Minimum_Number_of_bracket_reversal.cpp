#include <bits/stdc++.h>
using namespace std;

int func(string s) {
	int n = s.length();
	stack<char> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == '{')
			st.push(s[i]);
		else {
			if (st.empty() || st.top() == '}')
				st.push(s[i]);
			else
				st.pop();
		}
	}
	int oc = 0, cc = 0;
	while (!st.empty()) {
		if (st.top() == '{')
			oc++;
		else
			cc++;
		st.pop();
	}

	if ((oc & 1 && !(cc & 1)) || (cc & 1 && !(oc & 1)))
		return -1; // not possible

	if (oc & 1)
		return ((oc / 2) + (cc / 2) + 2);
	return (oc / 2) + (cc / 2);
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