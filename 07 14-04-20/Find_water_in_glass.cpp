#include <bits/stdc++.h>
using namespace std;

double func(int k, int x, int y) {
	double** dp = new double*[2];
	for (int i = 0; i <= 1; i++)
		dp[i] = new double[x + 1]();

	dp[0][0] = k;
	int temp = 0;
	double ans;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j <= x; j++)
			dp[temp ^ 1][j] = 0;
		for (int j = 0; j <= i; j++) {
			double w = dp[temp][j];
			double r = 0;
			if (w > 1) {
				r = w - 1;
				dp[temp][j] = 1;
			}
			dp[temp ^ 1][j] += r / 2;
			dp[temp ^ 1][j + 1] += r / 2;
		}
		temp ^= 1;
	}
	ans = dp[temp ^ 1][y - 1];
	for (int i = 0; i <= 1; i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k, i, j;
		cin >> k >> i >> j;
		cout << fixed << setprecision(6) << func(k, i, j) << endl;
	}
	return 0;
}