#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n) {
	if (n <= 1)
		return n;

	int* dp1 = new int[n]();
	int* dp2 = new int[n]();

	// left to right if found bigger hight dp[i] = dp[i-1] + 1 else dp[i+1] = 1
	// same from right to left
	// ans is max(ith index of both)

	dp1[0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1])
			dp1[i] = dp1[i - 1] + 1;
		else
			dp1[i] = 1;
	}

	dp2[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > arr[i + 1])
			dp2[i] = dp2[i + 1] + 1;
		else
			dp2[i] = 1;
	}

	for (int i = 0; i < n; i++)
		dp1[i] = max(dp1[i], dp2[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += dp1[i];
	delete [] dp1;
	delete [] dp2;
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

		cout << func(arr, n) << endl;
		delete [] arr;
	}
	return 0;
}