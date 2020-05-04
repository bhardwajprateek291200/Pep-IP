#include <bits/stdc++.h>
using namespace std;

bool func(string s) {
	unordered_map<char, int> m1, m2;
	int n = s.length();
	if (n <= 1)
		return 1;
	for (int i = 0; i < n; i++)
		m1[s[i] - 'a']++;

	for (auto x : m1)
		m2[x.second]++;

	if (m2.size() > 2)
		return 0;

	if (m2.size() == 1)
		return 1;

	int first, second, val1, val2;
	int i = 0;
	for (auto x : m2) {
		if (i & 1) {
			second = x.first;
			val2 = x.second;
		}
		else {
			first = x.first;
			val1 = x.second;
		}
		i++;
	}

	if (val1 > 1 && val2 > 1)
		return 0;

	if ((first == 1 && val1 == 1) || (second == 1 && val2 == 1))
		return 1;

	if (abs(first - second) <= 1)
		return 1;

	return 0;
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