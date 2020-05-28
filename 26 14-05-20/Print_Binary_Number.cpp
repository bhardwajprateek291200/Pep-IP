#include <bits/stdc++.h>
using namespace std;

void func(int n) {
	string s = "1";
	queue<string> q;
	int i = n;
	q.push(s);
	while (i--) {
		cout << q.front() << " ";
		string s = q.front();
		q.pop();
		q.push(s + "0");
		q.push(s + "1");
	}
	cout << endl;
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		func(n);
	}
	return 0;
}