#include <bits/stdc++.h>
using namespace std;

void func(int* arr, int n, int k) {
	// k-1 storage values for boyer moore algorithm but hashmap is good for this

	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	for (auto x : m) {
		if (x.second > n / k)
			cout << x.first << " ";
	}
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

		func(arr, n, k);

		delete [] arr;
	}
	return 0;
}