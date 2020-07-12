#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int n1, int n2) {
	if (n2 != 0)
		return gcd(n2, n1 % n2);
	else
		return n1;
}


int32_t main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << "Case " << i + 1;
		int gc = gcd(a, b);
		if (c % gc == 0)
			cout << ": Yes" << endl;
		else
			cout << ": No" << endl;
	}
	return 0;
}