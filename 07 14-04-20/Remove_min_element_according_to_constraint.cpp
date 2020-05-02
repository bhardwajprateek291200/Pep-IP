#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n) {
	if (n == 1)
		return 1;
	int mini, maxi;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		mini = maxi = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < mini)
				mini = arr[j];
			if (arr[j] > maxi)
				maxi = arr[j];
			if ((2 * mini) > maxi)
				ans = max(ans, j - i + 1);
		}
	}
	return (n - ans);
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