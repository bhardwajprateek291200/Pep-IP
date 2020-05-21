#include <bits/stdc++.h>
using namespace std;

bool func(int* arr, int n, int x) {
	if (n == 1)
		return 0;
	sort(arr, arr + n);
	int i = 0, j = 1;
	while (j < n) {
		if (arr[j] - arr[i] == x)
			return 1;
		else if (arr[j] - arr[i] < x)
			j++;
		else
			i++;
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
		cout << (func(arr, n, x) ? "1" : "-1") << endl;
		delete [] arr;
	}
	return 0;
}