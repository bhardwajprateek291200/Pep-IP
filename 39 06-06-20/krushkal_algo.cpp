#include <bits/stdc++.h>
using namespace std;

class edges {
public:
	int x, y, w;
};

bool comp(edges a, edges b) {
	return a.w < b.w;
}

int find(int x, vector<int> &parent) {
	if (x == parent[x])
		return x;
	int px = find(parent[x], parent);
	parent[x] = px;
	return px;
}

void union_(int x, int y, vector<int> &parent, vector<int> &rank) {
	int lx = find(x, parent);
	int ly = find(y, parent);
	if (lx != ly) {
		if (rank[x] < rank[y])
			parent[lx] = ly;
		else if (rank[x] > rank[y])
			parent[ly] = lx;
		else {
			parent[lx] = ly;
			rank[ly]++;
		}
	}
}

int32_t main() {
	int v, e;
	cin >> v >> e;
	edges* arr = new edges[e];
	for (int i = 0; i < e; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].w;
	}
	sort(arr, arr + e, comp);
	vector<int> parent(v);
	vector<int> rank(v, 1);
	for (int i = 0; i < v; i++)
		parent[i] = i;
	int cnt = 0;
	int i = 0;
	int ans = 0;
	while (cnt < v - 1) {
		edges temp = arr[i];
		i++;
		int lx = find(temp.x, parent);
		int ly = find(temp.y, parent);
		if (lx == ly)
			continue;
		cnt++;
		ans += temp.w;
		union_(temp.x, temp.y, parent, rank);
	}
	cout << ans << endl;
	return 0;
}