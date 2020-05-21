#include <bits/stdc++.h>
using namespace std;

int func(string S, int m, string T, int n) {
	int** dp = new int*[m + 1];
	for (int i = 0; i <= m; i++)
		dp[i] = new int[n + 1];

	// T string is empty
	for (int i = 0; i <= m; i++)
		dp[i][0] = 1;

	// S string is empty
	for (int i = 0; i <= n; i++)
		dp[0][i] = 100000;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char ch = S[i - 1];
			int k;
			for (k = j - 1; k >= 0; k--)
				if (T[k] == ch)
					break;
			// char not present in T
			if (k == -1)
				dp[i][j] = 1;
			else
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + 1);
		}
	}
	int ans = dp[m][n];
	for (int i = 0; i <= m; i++)
		delete [] dp[i];
	delete [] dp;
	if (ans == 100000)
		return -1;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string s, t;
		cin >> s >> t;
		cout << func(s, n, t, m) << endl;
	}
	return 0;
}