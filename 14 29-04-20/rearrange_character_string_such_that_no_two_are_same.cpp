#include <bits/stdc++.h>
using namespace std;

bool func(string s) {
	int n = s.length();
	if (n <= 1)
		return 1;

	unordered_map<char, int> m;
	for (int i = 0; i < n; i++)
		m[s[i]]++;

	priority_queue<int> pq;
	for (auto x : m)
		pq.push(x.second);

	int prev = pq.top() - 1;
	pq.pop();
	while (!pq.empty()) {
		int r = pq.top();
		pq.pop();
		if (prev > 0)
			pq.push(prev);
		prev = r - 1;
	}
	return prev < 1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << func(s) << endl;
	}
	return 0;
}