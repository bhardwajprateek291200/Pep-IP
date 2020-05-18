#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<long long,long long>
using namespace std;

int func(pii* arr, int n) {
	unordered_map<string, int> sm;
	unordered_map<long long, int> xm;
	unordered_map<long long, int> ym;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		string s = to_string(arr[i].ff) + "*" + to_string(arr[i].ss);

		if (xm.find(arr[i].ff) != xm.end())
			ans += xm[arr[i].ff];
		if (ym.find(arr[i].ss) != ym.end())
			ans += ym[arr[i].ss];
		if (sm.find(s) != sm.end())
			ans -= 2 * sm[s];

		sm[s]++;
		xm[arr[i].ff]++;
		ym[arr[i].ss]++;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		pii* arr = new pii[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i].ff >> arr[i].ss;

		cout << func(arr, n) << endl;

		delete [] arr;
	}
	return 0;
}