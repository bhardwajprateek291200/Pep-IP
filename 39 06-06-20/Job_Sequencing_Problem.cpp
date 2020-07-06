#include <bits/stdc++.h>
using namespace std;

struct node {
	int id, deadline, profit;
};

bool comp(node a, node b) {
	return a.profit > b.profit;
}

int find(int x, vector<int> &parent) {
	if (x == parent[x])
		return x;
	int px = find(parent[x], parent);
	parent[x] = px;
	return px;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		node* arr = new node[n];
		int max_deadline = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
			max_deadline = max(max_deadline, arr[i].deadline);
		}

		// union by rank is not helpful

		vector<int> parent(max_deadline + 1);
		for (int i = 0; i <= max_deadline; i++)
			parent[i] = i;
		int cnt = 0;
		int profit = 0;
		sort(arr, arr + n, comp);
		for (int i = 0; i < n; i++) {
			node temp = arr[i];
			int t = temp.deadline;
			int lx = find(t, parent);
			if (lx == 0)
				continue;
			cnt++;
			profit += temp.profit;
			parent[lx] = parent[lx - 1];
		}
		cout << cnt << " " << profit << endl;
	}
	return 0;
}