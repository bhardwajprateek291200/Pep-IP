#include <bits/stdc++.h>
using namespace std;

string func(int n, int d) {
	string ans = to_string(n / d);
	string temp = "";
	unordered_map<int, int> m;
	int r = n % d;
	while (r != 0 && m.find(r) == m.end()) {
		m[r] = temp.length();
		// cout << r << " " << m[r] << endl;
		int t = r * 10;
		temp += to_string(t / d);
		// cout << temp << endl;
		r = t % d;
	}
	if (r == 0 && m.size() == 0)
		return ans;
	if (r == 0)
		return ans + "." + temp;
	ans += ".";
	int id = m[r];
	// cout << id << " " << temp.length() << endl;
	for (int i = 0; i < id; i++)
		ans += temp[i];
	ans += "(";
	for (int i = id; i < temp.length(); i++)
		ans += temp[i];
	// cout << temp[0] << endl;
	ans += ")";
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		cout << func(n, d) << endl;
	}
	return 0;
}