#include <bits/stdc++.h>
using namespace std;

void func(vector<int> v, int n, int k) {
	vector<int> ans(n - k + 1);
	int id = -1;
	int sub = 0;
	for (int i = n - 1; i > n - k; i--) {
		if (v[i] < 0) {
			sub = v[i];
			id = i;
		}
	}
	for (int i = n - k; i >= 0; i--) {
		if (v[i] < 0) {
			ans[i] = v[i];
			id = i;
			sub = v[i];
		}
		else {
			if (id == -1)
				ans[i] = 0;
			else if (i + k - 1 >= id)
				ans[i] = sub;
			else
				ans[i] = 0;
		}
	}
	for (int i = 0; i < n - k + 1; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cin >> k;
		func(v, n, k);
	}
	return 0;
}