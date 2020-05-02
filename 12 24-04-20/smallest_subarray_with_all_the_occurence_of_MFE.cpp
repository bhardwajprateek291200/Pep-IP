#include <bits/stdc++.h>
using namespace std;

void func(int* arr, int n) {
	if (n == 0)
		return;
	unordered_map<int, pair<int, pair<int, int>>> m;
	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) == m.end()) {
			m[arr[i]].first = 1;
			m[arr[i]].second.first = i;
			m[arr[i]].second.second = i;
		}
		else {
			m[arr[i]].first++;
			m[arr[i]].second.second = i;
		}
	}

	int ans = 1;
	int i, j;
	i = j = 0;
	int freq = 1;
	for (auto x : m) {
		if (x.second.first > freq) {
			freq = x.second.first;
			ans = x.second.second.second - x.second.second.first + 1;
			i = x.second.second.first;
			j = x.second.second.second;
		}
		else if (x.second.first == freq) {
			int tempx, tempy;
			tempx = x.second.second.first;
			tempy = x.second.second.second;
			int tempans = tempy - tempx + 1;
			if (tempans < ans) {
				ans = tempans;
				i = tempx;
				j = tempy;
			}
			else if (tempans == ans) {
				if (tempx < i) {
					i = tempx;
					j = tempy;
				}
			}
		}
	}

	for (int k = i; k <= j; k++)
		cout << arr[k] << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		func(arr, n);

		delete [] arr;
	}
	return 0;
}