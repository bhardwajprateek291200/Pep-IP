#include <bits/stdc++.h>
using namespace std;
#define int long long

void func(vector<int> v, int n) {
	// similar to next greater element on left
	stack<int> s; // store idx
	s.push(n - 1);
	vector<int> ans(n);
	for (int i = n - 2; i >= 0; i--) {
		if (v[i] > v[s.top()]) {
			while (!s.empty() && v[i] > v[s.top()]) {
				int id = s.top();
				s.pop();
				ans[id] = id - i;
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = s.top() + 1;  // grater than all below its
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