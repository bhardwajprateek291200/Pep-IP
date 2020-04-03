#include <bits/stdc++.h>
using namespace std;

int func(int arr[][55], int n, int m) {
	int** dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[m]();
	}

	for (int i = 0; i < m; i++)
		dp[n - 1][i] = arr[n - 1][i];
	for (int i = 0; i < n; i++)
		dp[i][m - 1] = arr[i][m - 1];

	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			if (arr[i][j] == 0)
				continue;
			else
				dp[i][j] = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1])) + 1;
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] > result)
				result = dp[i][j];
		}
	}
	for (int i = 0; i < n; i++)
		delete [] dp[i];
	delete [] dp;
	return result;
}

int main() {
	int t;
	cin >> t;
	int arr[55][55];
	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];

		cout << func(arr, n, m) << endl;
	}
	return 0;
}