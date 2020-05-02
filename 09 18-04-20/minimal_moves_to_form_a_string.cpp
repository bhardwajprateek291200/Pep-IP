#include <bits/stdc++.h>
using namespace std;

int func(string s) {
	int n = s.length();
	int* dp = new int[n];
	for (int i = 0; i < n; i++)
		dp[i] = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			dp[i] = 1;
		else
			dp[i] = min(dp[i], dp[i - 1] + 1);

		if (i < n / 2) {
			int j = i + 1, k = 0;
			for (; k <= i; k++, j++) {
				if (s[j] != s[k])
					break;
			}
			if (k == i + 1)
				dp[j - 1] = dp[i] + 1;
		}
	}
	// for (int i = 0; i < n; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;
	int ans = dp[n - 1];
	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << func(s) << endl;
	}
	return 0;
}