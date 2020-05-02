#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n, int k) {
	if (n == 0)
		return 0;

	// kadane
	int* dp = new int[n];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] >= 0)
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
	}
	int sum = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];

	int ans = sum;
	for (int i = k; i < n; i++) {
		sum = sum + arr[i] - arr[i - k];
		ans = max(sum, max(ans, sum + dp[i - k]));
	}
	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int k;
		cin >> k;
		cout << func(arr, n, k) << endl;
		delete [] arr;
	}
	return 0;
}