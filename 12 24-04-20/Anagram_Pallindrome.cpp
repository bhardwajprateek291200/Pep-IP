#include <bits/stdc++.h>
using namespace std;

bool func(string s) {
	int n = s.length();
	if (n <= 1)
		return true;

	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[s[i]]++;

	int odd = 0;
	for (auto x : m) {
		if (x.second & 1)
			odd++;
		if (odd >= 2)
			return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << (func(s) ? "Yes" : "No") << endl;
	}
	return 0;
}