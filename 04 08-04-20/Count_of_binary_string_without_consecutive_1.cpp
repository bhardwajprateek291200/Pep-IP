#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int func(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 2;
	int cnt0 = 1;
	int cnt1 = 1;
	for (int i = 2; i <= n; i++) {
		int temp0, temp1;
		temp0 = (cnt0 + cnt1) % MOD;
		temp1 = cnt0;
		cnt0 = temp0;
		cnt1 = temp1;
	}

	return (cnt0 + cnt1) % MOD;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << func(n) << endl;
	}
	return 0;
}