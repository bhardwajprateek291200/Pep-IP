#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int c;
				cin >> c;
				if (c == 1) {
					arr[j]++;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] & 1) {
				cnt++;
			}
		}
		if (cnt == 2 || cnt == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}