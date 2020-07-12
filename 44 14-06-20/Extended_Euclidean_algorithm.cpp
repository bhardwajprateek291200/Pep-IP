#include <bits/stdc++.h>
using namespace std;
#define int long long

class node {
public:
	int x, y, gcd_;
};

node gcd(int n1, int n2) {
	if (n2 == 0) {
		node temp;
		temp.x = 1;
		temp.y = 0;
		temp.gcd_ = n1;
		return temp;
	}
	node temp = gcd(n2, n1 % n2);
	node nn;
	nn.x = temp.y;
	nn.y = temp.x - (n1 / n2) * temp.y;
	nn.gcd_ = temp.gcd_;
	return nn;
}


int32_t main() {
	int t;
	t = 2;
	while (t--) {
		int a, b;
		cin >> a >> b;
		node gc = gcd(a, b);
		cout << gc.x  << " " << gc.y << " " << gc.gcd_ << endl;
	}
	return 0;
}