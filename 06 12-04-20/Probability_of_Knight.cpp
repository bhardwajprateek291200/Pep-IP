#include <bits/stdc++.h>
#define ps(x,y)           fixed<<setprecision(y)<<x
using namespace std;

double func(int n, int x, int y, int k) {
	if (x < 0 || y < 0 || x > n || y > n )
		return 0;
	else if (k == 0)
		return 1;

	double** dp1 = new double*[n];
	for (int i = 0; i < n; i++)
		dp1[i] = new double[n]();

	double** dp2 = new double*[n];
	for (int i = 0; i < n; i++)
		dp2[i] = new double[n]();

	// swap(dp1, dp2);
	dp1[x][y] = 1;

	for (int i = 1; i <= k; i++) {
		for (int p = 0; p < n; p++) {
			for (int q = 0; q < n; q++) {
				// all moves
				if (p + 2 < n) {
					if (q + 1 < n)
						dp2[p + 2][q + 1] += dp1[p][q] / 8;
					if (q - 1 >= 0)
						dp2[p + 2][q - 1] += dp1[p][q] / 8;
				}
				if (q + 2 < n) {
					if (p + 1 < n)
						dp2[p + 1][q + 2] += dp1[p][q] / 8;
					if (p - 1 >= 0)
						dp2[p - 1][q + 2] += dp1[p][q] / 8;
				}
				if (p - 2 >= 0) {
					if (q + 1 < n)
						dp2[p - 2][q + 1] += dp1[p][q] / 8;
					if (q - 1 >= 0)
						dp2[p - 2][q - 1] += dp1[p][q] / 8;
				}
				if (q - 2 >= 0) {
					if (p + 1 < n)
						dp2[p + 1][q - 2] += dp1[p][q] / 8;
					if (p - 1 >= 0)
						dp2[p - 1][q - 2] += dp1[p][q] / 8;
				}
				dp1[p][q] = 0;
			}
		}
		swap(dp1, dp2);
	}

	double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			ans += dp1[i][j];
	}

	for (int i = 0; i < n; i++) {
		delete [] dp1[i];
		delete [] dp2[i];
	}
	delete [] dp1;
	delete [] dp2;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, y, k;
		cin >> n >> x >> y >> k;
		cout << ps(func(n, x, y, k), 6) << endl;
	}
	return 0;
}