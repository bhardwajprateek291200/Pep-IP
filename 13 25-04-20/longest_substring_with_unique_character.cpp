#include <bits/stdc++.h>
using namespace std;

int func(string s) {
	unordered_map<char, int> m;
	int n = s.length();
	if (n <= 1)
		return n;
	int start = 0;
	int e = 0;
	int l = 1;
	m[s[0]] = 0;
	for (e = 1; e < n; e++) {
		if (m.find(s[e]) != m.end()) {
			if (m[s[e]] >= start)
				start = m[s[e]] + 1;
		}
		m[s[e]] = e;
		l = max(l, e - start + 1);
		// cout << e << " " << start << " " << l << endl;
	}
	return l;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << func(s) << endl;
	}
	return 0;
}