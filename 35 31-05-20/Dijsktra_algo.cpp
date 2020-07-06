#include <bits/stdc++.h>
using namespace std;

class comp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int32_t main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push(make_pair(0, 0));
	vector<int> visit(n, -1);
	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		if (visit[temp.first] == -1) {
			visit[temp.first] = temp.second;
		}

		for (int i = 0; i < graph[temp.first].size(); i++) {
			if (visit[graph[temp.first][i].first] == -1) {
				pq.push(make_pair(graph[temp.first][i].first, graph[temp.first][i].second + temp.second));
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << visit[i] << " ";
	cout << endl;
	return 0;
}