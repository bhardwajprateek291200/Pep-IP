#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return arr[0];

	int** dp = new int*[n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[n];

	// initailise diagonal
	for (int i = 0; i < n; i++) {
		dp[i][i] = arr[i];
	}
	// 2 diagonal
	for (int i = 0; i < n - 1; i++)
		dp[i][i + 1] = max(arr[i], arr[i + 1]);

	for (int cnt = 2; cnt < n; cnt++) {
		for (int i = 0; i < n - cnt; i++) {
			dp[i][i + cnt] = max(arr[i] + min(dp[i + 2][i + cnt], dp[i + 1][i + cnt - 1]),
			                     arr[i + cnt] + min(dp[i + 1][i + cnt], dp[i][i + cnt - 2]));
			// taking that we took max  of first or last and correspond another player try to choose first and last in such way to
			// provide us minima
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	int ans = dp[0][n - 1];
	for (int i = 0; i < n; i++)
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
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << func(arr, n) << endl;
	}
	return 0;
}