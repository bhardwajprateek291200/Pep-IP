#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000

void floyd_warshall(vector<vector<int>>& arr, int v) {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			for (int k = 0; k < v; k++) {
				if (arr[j][i] == MAX || arr[i][k] == MAX)
					continue;
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int v;
		cin >> v;
		vector<vector<int>> arr(v, vector<int>(v));
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				cin >> arr[i][j];
			}
		}
		floyd_warshall(arr, v);
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (arr[i][j] == MAX)
					cout << "INF" << " ";
				else
					cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}