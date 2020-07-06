#include <bits/stdc++.h>
using namespace std;

struct edges {
	int u, v, w;
};

bool bellman_ford(vector<edges> graph, int v, int e) {
	vector<int> temp(v, INT_MAX);
	temp[0] = 0;
	for (int i = 0; i < v - 1; i++) {
		for (int j = 0; j < e; j++) {
			int u, v, w;
			u = graph[j].u;
			v = graph[j].v;
			w = graph[j].w;
			if (temp[u] == INT_MAX)
				continue;
			temp[v] = min(temp[v], temp[u] + w);
		}
	}

	for (int j = 0; j < e; j++) {
		int u, v, w;
		u = graph[j].u;
		v = graph[j].v;
		w = graph[j].w;
		if (temp[u] + w < temp[v])
			return 1;
	}
	return 0;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<edges> graph(m);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[i].u = u;
			graph[i].v = v;
			graph[i].w = w;
		}
		// negative cycle detection
		cout << bellman_ford(graph, n, m) << endl;
	}
	return 0;
}