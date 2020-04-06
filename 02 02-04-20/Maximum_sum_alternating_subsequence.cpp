#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	vector<pair<int, int> > p(n);
	p[n - 1].first = v[n - 1]; // this is inc
	p[n - 1].second = v[n - 1]; // this is dec
	for (int i = n - 2; i >= 0; i--) {
		p[i].first = p[i].second = v[i];
		for (int j = i + 1; j < n; j++) {
			if (v[j] < v[i])
				p[i].first = max(p[i].first, p[j].second + v[i]);  // we look smaller values who are at decrese level
			if (v[j] > v[i])
				p[i].second = max(p[i].second, p[j].first + v[i]);  // look for bigger element at inc level
		}
	}

	cout << p[0].first << endl;  // sequence should start from 1
	p.clear();
	v.clear();

	return 0;
}