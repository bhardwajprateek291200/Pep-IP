#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(vector<int> v, int n) {
	int ans = INT_MIN;
	for (int i = 1; i < n; i++)
		if (v[i] + v[i - 1] > ans)
			ans = v[i] + v[i - 1];
	return ans;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << func(v, n) << endl;
	}
	return 0;
}