#include <bits/stdc++.h>
using namespace std;

int func(string arr) {
	int n = arr.length();
	int curr0 = 0;
	int curr1 = 0;
	int curr2 = 0;
	unordered_map<string, int> m;
	string s = to_string(curr0 - curr1) + '*' + to_string(curr0 - curr2);
	m[s] = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == '1')
			curr1++;
		else if (arr[i] == '0')
			curr0++;
		else
			curr2++;
		string r = to_string(curr0 - curr1) + '*' + to_string(curr0 - curr2);
		if (m.find(r) != m.end())
			ans += m[r];

		m[r]++;
	}
	return ans;

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