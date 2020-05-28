#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int q;
	cin >> q;
	int i = 0;
	for (; i * i < n; i++);
	int len = i;
	vector<int> temp(len, INT_MAX);
	for (int i = 0; i < n; i++) {
		temp[i / len] = min(temp[i / len], v[i]);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int ans = INT_MAX;
		while (l <= r) {
			if (l % len == 0 && l + len - 1 <= r) {
				ans = min(ans, temp[l / len]);
				l = l + len;
			}
			else {
				ans = min(ans, v[l]);
				l++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}