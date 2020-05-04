#include <bits/stdc++.h>
using namespace std;
#define int               long long

vector<int> func(int n) {
	vector<int> ans;
	if (n <= 9) {
		ans.push_back(n);
		return ans;
	}
	int d = 9;
	while (n >= 10) {
		while (n % d)
			d--;
		if (d == 1) {
			ans.clear();
			return ans;
		}
		ans.push_back(d);
		n /= d;
	}
	ans.push_back(n);
	return ans;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ans = func(n);

		if (ans.size() == 0)
			cout << -1;
		else
			for (int i = ans.size() - 1; i >= 0; i--)
				cout << ans[i];
		cout << endl;
	}
	return 0;
}