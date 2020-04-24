#include <bits/stdc++.h>
using namespace std;

int func(string x, int n, string y, int m, string z, int k) {
	int*** dp = new int**[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int*[m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			dp[i][j] = new int[k + 1]();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int l = 1; l <= k; l++) {
				if (x[i - 1] == y[j - 1] && y[j - 1] == z[l - 1])
					dp[i][j][l] = dp[i - 1][j - 1][l - 1] + 1;
				else
					dp[i][j][l] = max(dp[i - 1][j][l], max(dp[i][j - 1][l], dp[i][j][l - 1]));
			}
		}
	}
	int ans = dp[n][m][k];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			delete [] dp[i][j];
	}
	for (int i = 0; i <= n; i++)
		delete dp[i];

	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		string x, y, z;
		cin >> x >> y >> z;
		cout << func(x, n, y, m, z, k) << endl;
	}
	return 0;
}