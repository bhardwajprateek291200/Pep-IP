#include <bits/stdc++.h>
using namespace std;

int func(int m, int n, int revenue[], int x[], int t) {
	if (n == 0)
		return 0;

	unordered_map<int, int> s;
	for (int i = 0; i < n; i++)
		s.insert(make_pair(x[i], i));

	int dp[m + 1];
	memset(dp, 0, sizeof(dp));

	// taking revenue at ith will include (ith + (i-t)th) if possible
	for (int i = x[0]; i <= m; i++) {
		dp[i] = dp[i - 1];
		if (s.find(i) != s.end()) {
			int temp = revenue[s[i]] + ((i - t - 1 >= 0) ? dp[i - t - 1] : 0);
			dp[i] = max(dp[i], temp);
			// cout << temp << endl;
		}
		// cout << dp[i] << " ";
	}
	// cout << endl;
	return dp[m];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		int revenue[n];
		int x[n];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		for (int i = 0; i < n; i++)
			cin >> revenue[i];
		int t;
		cin >> t;

		cout << func(m, n, revenue, x, t) << endl;
	}

	return 0;
}

/*
15
15
4
6 9 12 14
5 6 3 7
2
*/