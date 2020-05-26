#include <bits/stdc++.h>
using namespace std;

int func(string s) {
	int n = s.length();
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			st.push(i);
		else {
			if (st.empty())
				st.push(i);
			else if (s[st.top()] != '(')
				st.push(i);
			else {
				st.pop();
				if (st.empty())
					ans = max(ans, i + 1);
				else
					ans = max(ans, i - st.top());
			}
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