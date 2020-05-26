#include <bits/stdc++.h>
using namespace std;
#define int long long

void func(vector<int> v, int n) {
	stack<int> s; // store idx
	s.push(0);
	vector<int> ans(n);
	for (int i = 1; i < n; i++) {
		if (v[i] > v[s.top()]) {
			while (!s.empty() && v[i] > v[s.top()]) {
				int id = s.top();
				s.pop();
				ans[id] = v[i];
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		func(arr, n);
	}
	return 0;
}