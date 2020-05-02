#include <bits/stdc++.h>
using namespace std;

int func(string s, int n) {
	if (n <= 1)
		return n;

	int** dp = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = dp[0][i] = 0;

	//lcs
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == s[j - 1] && i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int ans = dp[n][n];
	for (int i = 0; i <= n; i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		// cout << s << endl;
		cout << func(s, n) << endl;
	}
	return 0;
}