#include <bits/stdc++.h>
using namespace std;

int func(int* arrival, int* departure, int n) {
	sort(arrival, arrival + n);
	sort(departure, departure + n); // sort differently does not effect the ans
	int cnt = 1;
	int ans = -1;
	int i = 1, j = 0;
	while (i < n && j < n) {
		ans = max(ans, cnt);
		if (departure[j] >= arrival[i]) {
			cnt++;
			i++;
		}
		else {
			cnt--;
			j++;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* arrival = new int[n];
		int* departure = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arrival[i];
		for (int i = 0; i < n; i++)
			cin >> departure[i];
		cout << func(arrival, departure, n) << endl;
		delete [] arrival;
		delete [] departure;
	}
	return 0;
}