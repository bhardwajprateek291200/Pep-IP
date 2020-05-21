#include <bits/stdc++.h>
using namespace std;

bool arr[10001];

void func() {
	for (int i = 2; i * i <= 10000; i++) {
		if (arr[i])
			for (int j = 2; j * i <= 10000; j++)
				arr[i * j] = false;
	}
}

int main() {
	int t;
	cin >> t;
	memset(arr, -1, sizeof(arr));
	func();
	while (t--) {
		int n;
		cin >> n;
		for (int i = 2; i <= n; i++)
			if (arr[i])
				cout << i << " ";

		cout << endl;
	}
	return 0;
}