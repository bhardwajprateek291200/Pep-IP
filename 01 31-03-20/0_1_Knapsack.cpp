#include <bits/stdc++.h>
using namespace std;

int func(int val[], int wt[], int n, int w) {
	int** dp = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new int[w + 1]();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			dp[i][j] = dp[i - 1][j];
			if (wt[i - 1] <= j)
				dp[i][j] = max(dp[i][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
		}
	}
	int result = dp[n][w];
	for (int i = 0; i <= n; i++)
		delete [] dp[i];
	delete [] dp;
	return result;
}

int main() {
	int t;
	cin >> t;
	int val[1005];
	int wt[1005];
	while (t--) {
		int n, w;
		cin >> n >> w;

		for (int i = 0; i < n; i++)
			cin >> val[i];

		for (int i = 0; i < n; i++)
			cin >> wt[i];

		cout << func(val, wt, n, w) << endl;
	}
	return 0;
}