#include <bits/stdc++.h>
using namespace std;

int pow(int a, int b) {
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	int temp = pow(a * a, b / 2);
	if (b & 1)
		temp = temp * a;
	return temp;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << pow(a, b) << endl;
	return 0;
}