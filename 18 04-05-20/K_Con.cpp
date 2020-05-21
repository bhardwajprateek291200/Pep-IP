#include <bits/stdc++.h>
using namespace std;

long long func(int* arr, int n, int k) {

	long long currsum = arr[0];
	long long maxsum = arr[0];
	long long sum = arr[0];

	for (int i = 1; i < n; i++) {
		sum += arr[i];
		if (currsum < 0)
			currsum = 0;
		currsum += arr[i];
		maxsum = max(maxsum, currsum);
	}
	if (k == 1)
		return maxsum;

	for (int i = 0; i < n; i++) {
		if (currsum < 0)
			currsum = 0;
		currsum += arr[i];
		maxsum = max(maxsum, currsum);
	}

	if (sum > 0)
		return sum * (k - 2) + maxsum;
	return maxsum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << func(arr, n, k) << endl;

		delete [] arr;
	}
	return 0;
}