#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n) {
	if (n <= 1)
		return n;

	int ans = 0;
	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		int mini = arr[i];
		int maxi = arr[i];
		for (int j = i; j < n; j++) {
			if (arr[j] > maxi )
				maxi = arr[j];
			else if (arr[j] < mini)
				mini = arr[j];

			if (!s.insert(arr[j]).second)
				break;
			if (s.size() == maxi - mini + 1 && ans < maxi - mini + 1)
				ans = maxi - mini + 1;
		}
		s.clear();
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << func(arr, n) << endl;
	}
	return 0;
}