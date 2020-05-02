#include <bits/stdc++.h>
using namespace std;

int func(int* arr, int n) {
	int curr0 = 0;
	int curr1 = 0;
	unordered_map<int, int> m;
	m[0] = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i])
			curr1++;
		else
			curr0++;
		int r = curr1 - curr0;
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