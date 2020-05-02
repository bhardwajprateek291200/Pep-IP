#include <bits/stdc++.h>
using namespace std;


// using palindromic subsequence code
int func(string s, int n, int k) {
	if (n <= 1)
		return 1;

	int** dp = new int*[n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[n];

	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 2;
		else
			dp[i][i + 1] = 1;

	}

	for (int cnt = 2; cnt < n; cnt++) {
		for (int i = 0; i < n - cnt; i++) {
			int j = i + cnt;
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
		}
	}

	int ans = dp[0][n - 1];
	for (int i = 0; i < n; i++)
		delete [] dp[i];

	delete [] dp;
	return (n - ans <= k);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		cout << func(s, n, k) << endl;
	}
	return 0;
}