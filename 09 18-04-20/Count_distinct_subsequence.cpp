#include <bits/stdc++.h>
#define MOD 1000000007
const int MAX_CHAR = 256;
using namespace std;

int func(string s) {
	int n = s.length();
	int* dp = new int[n + 1];
	dp[0] = 1;

	vector<int> last(MAX_CHAR, -1);

	for (int i = 1; i <= n; i++) {
		dp[i] = (2 * dp[i - 1]) % MOD;
		if (last[s[i - 1]] != -1)
			dp[i] = (dp[i] - dp[last[s[i - 1]]]) % MOD;
		if (dp[i] < 0)
			dp[i] += MOD;
		last[s[i - 1]] = (i - 1);
	}
	// for (int i = 0; i <= n; i++)
	// 	cout << dp[i] << " ";
	// cout << endl;
	int ans = dp[n];
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