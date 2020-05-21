#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int n) {
	int i = n, j = n, l = 0;
	for (int k = 0; k < n; k++)
		if (arr[k] != 0) {
			i = k;
			break;
		}
	for (int k = i; k < n; k++)
		if (arr[k] != 1) {
			j = k;
			break;
		}
	for (int k = n - 1; k >= 0; k--)
		if (arr[k] != 2) {
			l = k;
			break;
		}
	while (j <= l) {
		if (arr[j] == 0) {
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else if (arr[j] == 2) {
			swap(arr[j], arr[l]);
			l--;
		}
		else
			j++;
	}
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
		func(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete [] arr;
	}
	return 0;
}