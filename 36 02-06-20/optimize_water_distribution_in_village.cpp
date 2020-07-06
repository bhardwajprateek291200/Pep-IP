#include <bits/stdc++.h>
using namespace std;

class comp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int32_t main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		graph[i + 1].push_back(make_pair(0, w));
		graph[0].push_back(make_pair(i + 1, w));
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push(make_pair(1, 0));
	int ans = 0;
	unordered_set<int> s;
	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		if (s.find(temp.first) == s.end()) {
			ans += temp.second;
			s.insert(temp.first);
		}

		for (int i = 0; i < graph[temp.first].size(); i++) {
			if (s.find(graph[temp.first][i].first) == s.end()) {
				pq.push(make_pair(graph[temp.first][i].first, graph[temp.first][i].second));
			}
		}
	}
	cout << ans << endl;
	return 0;
}