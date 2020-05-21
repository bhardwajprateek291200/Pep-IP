#include <bits/stdc++.h>
using namespace std;

int func(int x) {
	x = abs(x);
	for (int i = 0; ; i++) {
		int sum = (i * (i + 1)) / 2;
		if (sum >= x) {
			int diff = sum - x;
			if (diff % 2 == 0)
				return i;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << func(x) << endl;
	}
	return 0;
}