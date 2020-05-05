#include <bits/stdc++.h>
using namespace std;

// MAX heap

void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void helper(int arr[], int n, int idx) {
	if (2 * idx + 1 >= n)
		return;
	if (2 * idx + 2 < n && arr[2 * idx + 1] < arr[idx] && arr[2 * idx + 2] < arr[idx])
		return;
	if (2 * idx + 2 >= n && arr[2 * idx + 1] < arr[idx])
		return;

	if (2 * idx + 2 < n) {
		int val = max(arr[2 * idx + 1], arr[2 * idx + 2]);
		int temp = arr[idx];
		if (val > temp) {
			arr[idx] = val;
			if (val == arr[2 * idx + 1]) {
				arr[2 * idx + 1] = temp;
				helper(arr, n, 2 * idx + 1);
			}
			else {
				arr[2 * idx + 2] = temp;
				helper(arr, n, 2 * idx + 2);
			}
		}
	}
	else {
		int val = arr[2 * idx + 1];
		int temp = arr[idx];
		if (val > temp) {
			arr[idx] = val;
			arr[2 * idx + 1] = temp;
			helper(arr, n, 2 * idx + 1);
		}
	}
}

void func(int arr[], int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (2 * i + 1 < n && 2 * i + 2 < n) {
			int val1 = arr[2 * i + 1];
			int val2 = arr[2 * i + 2];
			if (val1 > val2) {
				if (val1 > arr[i]) {
					swap(arr[i], arr[2 * i + 1]);
					helper(arr, n, 2 * i + 1);
				}
			}
			else {
				if (val2 > arr[i]) {
					swap(arr[i], arr[2 * i + 2]);
					helper(arr, n, 2 * i + 2);
				}
			}
		}
		else if (2 * i + 1 < n) {
			int val1 = arr[2 * i + 1];
			if (val1 > arr[i]) {
				swap(arr[i], arr[2 * i + 1]);
				helper(arr, n, 2 * i + 1);
			}
		}
	}
	print(arr, n);
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

		func(arr, n);
	}
	return 0;
}