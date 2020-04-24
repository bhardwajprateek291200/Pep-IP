#include <bits/stdc++.h>
using namespace std;

int func(int n, int k) {
	int** dp = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		dp[i] = new int[k + 1]();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			// condition
			if (j == 1 || i == j)
				dp[i][j] = 1;
			else {
				// add in existing one
				dp[i][j] = k * dp[i - 1][k];

				// make a new one
				dp[i][j] += dp[i - 1][k - 1];
			}
		}
	}
	int ans = dp[n][k];
	for (int i = 0; i <= n; i++)
		delete [] dp[i];
	delete [] dp;
	return ans;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << func(n, k) << endl;
	}
	return 0;
}