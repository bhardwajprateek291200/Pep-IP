#include <bits/stdc++.h>
using namespace std;

int func(int* arr, int n, int k) {
	int currsum = 0;
	unordered_map<int, int> m; // store reminder count
	m[0] = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		currsum += arr[i];
		int r = currsum % k;
		if (r < 0)
			r += k;
		if (m.find(r) != m.end())
			ans += m[r];

		m[r]++;
	}
	return ans;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int*arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << func(arr, n, k) << endl;

		delete [] arr;
	}
	return 0;
}