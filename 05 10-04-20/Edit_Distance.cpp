#include <bits/stdc++.h>
using namespace std;

int func(string x, int p, string y, int q) {
	int** dp = new int*[p + 1];
	for (int i = 0; i <= p; i++)
		dp[i] = new int[q + 1];

	// initialise
	for (int i = 1; i <= p; i++)
		dp[i][0] = i;
	for (int i = 1; i <= q; i++)
		dp[0][i] = i;
	dp[0][0] = 0;

	for (int i = 1; i <= p; i++) {
		for (int j = 1; j <= q; j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// insert : dp[i][j-1]
			// replace : dp[i-1][j-1]
			// remove : dp[i-1][j]
			else
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
		}
	}

	int ans = dp[p][q];
	for (int i = 0; i <= p; i++)
		delete [] dp[i];
	delete [] dp;

	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int p, q;
		cin >> p >> q;
		string x, y;
		cin >> x >> y;
		cout << func(x, p, y, q) << endl;
	}
	return 0;
}