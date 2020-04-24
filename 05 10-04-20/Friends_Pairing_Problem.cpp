#include <bits/stdc++.h>
#define int               long long
using namespace std;
#define MOD 1000000007

int func(int n) {
	if (n <= 2)
		return n;
	int temp1 = 1;
	int temp2 = 2;
	for (int i = 3; i <= n; i++) {
		// single
		int temp = temp2 % MOD;
		// pair
		temp += ((i - 1) * temp1) % MOD;
		temp %= MOD;
		swap(temp2, temp);
		swap(temp1, temp);
	}
	return temp2;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << func(n) << endl;
	}
	return 0;
}
