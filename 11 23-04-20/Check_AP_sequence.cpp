#include <bits/stdc++.h>
using namespace std;

bool func(int* arr, int n) {
	if (n <= 2)
		return true;

	int min1 = min(arr[0], arr[1]);
	int min2 = max(arr[0], arr[1]);

	for (int i = 2; i < n; i++) {
		int temp = arr[i];
		if (temp < min1)
			swap(min1, temp);
		if (temp < min2)
			min2 = temp;
	}

	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	m[min1]--;
	if (m[min1] == 0)
		m.erase(min1);
	m[min2]--;
	if (m[min2] == 0)
		m.erase(min2);
	int d = min2 - min1;

	while (m.size() > 0) {
		int temp = d + min2;
		min2 = temp;
		if (m.find(temp) == m.end())
			return false;
		m[temp]--;
		if (m[temp] == 0)
			m.erase(temp);
	}
	return true;
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

		cout << (func(arr, n) ? "YES" : "NO") << endl;

		delete [] arr;
	}
	return 0;
}