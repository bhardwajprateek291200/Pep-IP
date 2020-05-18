#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

class comp {
public:
	bool operator()(pii a, pii b) {
		return a.ff > b.ff;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		// input
		int n;
		cin >> n;  //number of people
		priority_queue<pii, vector<pii>, comp> pq;
		for (int i = 0; i < n; i++) {
			int k;   // number of items for a specific people
			cin >> k;
			for (int j = 0; j < k; j++) {
				int s, e;  // start, end time
				cin >> s >> e;
				// mainatin priority queue
				pq.push(make_pair(s, e));
			}
		}

		// algo
		vector<pii> ans;
		int e = pq.top().ss;
		pq.pop();
		while (!pq.empty()) {
			pii temp = pq.top();
			pq.pop();
			if (temp.ff > e)
				ans.push_back(make_pair(e, temp.ff));
			e = max(e, temp.ss);
		}

		// printing
		for (auto x : ans)
			cout << x.ff << " " << x.ss << endl;
	}
	return 0;
}