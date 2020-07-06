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
	while (t--) {
		int a, b;
		cin >> a >> b;
		int gc = gcd(a, b);
		cout << gc << " ";
		cout << (a * b) / gc << endl;
	}
	return 0;
}