#include <bits/stdc++.h>
using namespace std;

// longest consecutive sequence
int func(int* arr, int n) {
	if (n <= 1)
		return 0;

	unordered_map<int, int> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		m[arr[i]] = 1;
		if (m.find(arr[i] - 1) != m.end()) {
			m[arr[i]] = max(m[arr[i]], m[arr[i] - 1] + 1);
		}
		if (ans < m[arr[i]])
			ans = m[arr[i]];
	}
	return n - ans;
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