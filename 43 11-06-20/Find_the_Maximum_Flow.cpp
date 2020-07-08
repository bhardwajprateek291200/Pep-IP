#include<bits/stdc++.h>
using namespace std;

/* Returns true if there is a path from source 's' to sink 't' in
residual graph. Also fills parent[] to store the path */
bool bfs(int** rGraph, int s, int t, int* &parent, int n) {
	bool* visited = new bool[n]();
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty()) {
		int u = q.front();
		if (u == t) {
			delete [] visited;
			return true;
		}
		q.pop();
		for (int v = 0; v < n; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	delete [] visited;
	return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int** graph, int s, int t, int n) {

	// Create a residual graph and fill the residual graph with
	// given capacities in the original graph as residual capacities
	// in residual graph
	int** rgraph = new int*[n];
	for (int i = 0; i < n; i++)
		rgraph[i] = new int[n]();
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			rgraph[u][v] = graph[u][v];

	int* parent = new int[n];

	int max_flow = 0;

	// Augment the flow while tere is path from source to sink
	while (bfs(rgraph, s, t, parent, n)) {

		// Find minimum residual capacity of the edges along the
		// path filled by BFS. Or we can say find the maximum flow
		// through the path found.
		int path_flow = INT_MAX;
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			path_flow = min(path_flow, rgraph[u][v]);
		}
		// update residual capacities of the edges and reverse edges
		// along the path
		for (int v = t; v != s; v = parent[v]) {
			int u = parent[v];
			rgraph[u][v] -= path_flow;
			rgraph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	delete [] parent;
	for (int i = 0; i < n; i++)
		delete [] rgraph[i];
	delete [] rgraph;

	// Return the overall flow
	return max_flow;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int** graph = new int*[n];
		for (int i = 0; i < n; i++)
			graph[i] = new int[n]();
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			x--;
			y--;
			// edges and its weight can repeat
			graph[x][y] += w;
			graph[y][x] += w;
		}
		cout << fordFulkerson(graph, 0, n - 1, n) << endl;
		for (int i = 0; i < n; i++)
			delete [] graph[i];
		delete [] graph;
	}

	return 0;
}
