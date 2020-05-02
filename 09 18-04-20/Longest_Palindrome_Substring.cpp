#include <bits/stdc++.h>
using namespace std;

string func(string s) {
	int n = s.length();
	if (n <= 1)
		return s;

	bool** dp = new bool*[n];
	for (int i = 0; i < n; i++)
		dp[i] = new bool[n]();

	int ans = 1;
	int idx = 0;
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			if (ans < 2) {
				ans = 2;
				idx = i;
			}
		}
		else
			dp[i][i + 1] = false;

	}

	for (int cnt = 2; cnt < n; cnt++) {
		for (int i = 0; i < n - cnt; i++) {
			int j = i + cnt;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1];
				if (dp[i][j] && ans < j - i + 1) {
					// cout << dp[i][j] << endl;
					// cout << cnt << endl;
					ans = j - i + 1;
					idx = i;
				}
			}
			else
				dp[i][j] = false;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	for (int i = 0; i < n; i++)
		delete [] dp[i];

	delete [] dp;
	string str = "";
	for (int i = 0; i < ans; i++)
		str += s[i + idx];
	return str;
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