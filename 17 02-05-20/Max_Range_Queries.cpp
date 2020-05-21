#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define size 100000

int func(int n, int k, pii* v) {
	int arr[size] = {0};
	for (int i = 0; i < n; i++) {
		int s, e;
		s = v[i].ff - 1;
		e = v[i].ss - 1;
		arr[s] += 1;
		if (e + 1 < size)
			arr[e + 1] -= 1;
	}

	for (int i = 1; i < size; i++)
		arr[i] = arr[i] + arr[i - 1];

	int cnt1[size] = {0};
	int cnt2[size] = {0};

	if (arr[0] == k)
		cnt1[0] = 1;
	else if (arr[0] == k + 1)
		cnt2[0] = 1;

	for (int i = 1; i < size; i++) {
		cnt1[i] = cnt1[i - 1];
		cnt2[i] = cnt2[i - 1];
		if (arr[i] == k)
			cnt1[i] += 1;
		else if (arr[i] == k + 1)
			cnt2[i] += 1;
	}

	int cnt = cnt1[size - 1];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int s, e, temp1 = 0, temp2 = 0;
		s = v[i].ff - 1;
		e = v[i].ss - 1;

		//k
		if (s > 0)
			temp1 -= cnt1[s - 1];
		temp1 += cnt1[e];

		//k+1
		temp2 += cnt2[e];
		if (s > 0)
			temp2 -= cnt2[s - 1];

		ans = max(cnt - temp1 + temp2, ans);
	}
	return ans;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		pii *v = new pii[n];
		for (int i = 0; i < n; i++)
			cin >> v[i].ff >> v[i].ss;
		cout << func(n, k, v) << endl;
		delete [] v;
	}
	return 0;
}