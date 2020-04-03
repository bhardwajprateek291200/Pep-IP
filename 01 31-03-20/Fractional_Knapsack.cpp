#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return (a.first / float(a.second)) > (b.first / float(b.second));
}

float func(int n, vector<pair<int, int> > arr, int w) {
	sort(arr.begin(), arr.end(), comp);
	float ans = 0;
	for (int i = 0; i < n && w > 0; i++) {
		if (arr[i].second <= w) {
			w -= arr[i].second;
			ans += arr[i].first;
		}
		else {
			ans += (float(arr[i].first) * w ) / float(arr[i].second);
			w = 0;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++) {
			int val, wt;
			cin >> val >> wt;
			v.push_back(make_pair(val, wt));
		}
		cout << fixed << setprecision(2) << func(n, v, w) << endl;
		v.clear();
	}
	return 0;
}
