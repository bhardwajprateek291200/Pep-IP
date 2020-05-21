#include <bits/stdc++.h>
using namespace std;

bool func(int* arr, int n, int x) {
	sort(arr, arr + n);
	int i = 0, j = n - 1;
	while (i < j) {
		if (arr[i] + arr[j] == x)
			return 1;
		else if (arr[i] + arr[j] < x)
			i++;
		else
			j--;
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << (func(arr, n, x) ? "Yes" : "No") << endl;
		delete [] arr;
	}
	return 0;
}