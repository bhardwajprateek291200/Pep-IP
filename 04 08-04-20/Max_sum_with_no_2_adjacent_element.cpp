#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return arr[0];

	int inc = arr[0];
	int ninc = 0;

	for (int i = 1; i < n; i++) {
		int tempinc, tempninc;
		tempinc = ninc + arr[i];
		tempninc = max(inc, ninc);
		inc = tempinc;
		ninc = tempninc;
	}

	return max(inc, ninc);
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