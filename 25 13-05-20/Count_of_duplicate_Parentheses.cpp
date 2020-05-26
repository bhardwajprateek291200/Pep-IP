#include <bits/stdc++.h>
using namespace std;

int func(string s) {
	int n = s.length();
	stack<char> st;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != ')')
			st.push(s[i]);
		else {
			int cnt = 0;
			while (st.top() != '(') {
				cnt++;
				st.pop();
			}
			st.pop();
			if (cnt == 0)
				ans += 2;
		}
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