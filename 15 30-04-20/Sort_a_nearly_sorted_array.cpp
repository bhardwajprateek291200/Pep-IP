#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};

void func(int arr[], int n, int k) {
	if (n <= 1 || k == 0)
		print(arr, n);

	priority_queue<int, vector<int>, comparator> pq;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i <= k)
			pq.push(arr[i]);
		else {
			arr[cnt] = pq.top();
			cnt++;
			pq.pop();
			pq.push(arr[i]);
		}
	}
	while (!pq.empty()) {
		arr[cnt++] = pq.top();
		pq.pop();
	}

	print(arr, n);
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		func(arr, n, k);
	}
	return 0;
}