#include <bits/stdc++.h>
using namespace std;

long long arr[31][10];

void func() {
	for (int i = 0; i < 10; i++) {
		arr[0][i] = 0;
		arr[1][i] = 1;
	}
	unordered_map<int, string> m;
	m[0] = "08";
	m[1] = "124";
	m[2] = "2135";
	m[3] = "326";
	m[4] = "4157";
	m[5] = "52468";
	m[6] = "6359";
	m[7] = "748";
	m[8] = "85790";
	m[9] = "968";
	m[0] = "08";
	for (int i = 2; i <= 30; i++) {
		for (int j = 0; j < 10; j++) {
			int n = m[j].length();
			long long cnt = 0;
			for (int k = 0; k < n; k++) {
				int temp = m[j][k] - '0';
				cnt += arr[i - 1][temp];
			}
			arr[i][j] = cnt;
		}
	}
}


int main() {
	int t;
	cin >> t;
	func();
	while (t--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < 10; i++)
			ans += arr[n][i];
		cout << ans << endl;
	}
	return 0;
}