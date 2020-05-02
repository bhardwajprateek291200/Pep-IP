#include <bits/stdc++.h>
using namespace std;

int func(int* arr, int n) {
	int maxi = 0;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			curr = 0;
		else
			curr++;

		if (curr > maxi)
			maxi = curr;
	}
	return maxi;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int*arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << func(arr, n) << endl;

		delete [] arr;
	}
	return 0;
}