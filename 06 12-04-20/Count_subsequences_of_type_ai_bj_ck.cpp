#include <bits/stdc++.h>
using namespace std;

int func(string s) {
	// maintain 3 variables a : store the number of subsequence en as ..a..
	//						b : store the number of subsequence en as ..a...b..
	//						c : store the number of subsequence en as ..a...b...c..
	int a, b, c;
	a = b = c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a')
			a = a + a + 1;
		else if (s[i] == 'b')
			b = b + b + a;
		else
			c = c + c + b;
	}
	return c;
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