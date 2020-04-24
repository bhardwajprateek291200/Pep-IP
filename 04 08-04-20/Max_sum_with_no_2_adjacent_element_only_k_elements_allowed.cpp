#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int** inc = new int*[n];
	for (int i = 0; i < n; i++)
		inc[i] = new int[k + 1];
	int** exc = new int*[n];
	for (int i = 0; i < n; i++) {
		exc[i] = new int[k + 1];
	}

	for (int i = 0; i < n; i++) {
		inc[i][0] = 0;
		exc[i][0] = 0;
	}
	for (int i = 0; i <= k; i++) {
		inc[0][i] = arr[0];
		exc[0][i] = 0;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			inc[i][j] = arr[i] + exc[i - 1][j - 1];
			exc[i][j] = max(exc[i - 1][j], inc[i - 1][j]);
		}
	}

	cout << max(inc[n - 1][k], exc[n - 1][k]) << endl;
	for (int i = 0; i < n; i++) {
		delete [] inc[i];
		delete [] exc[i];
	}
	delete [] inc;
	delete [] exc;


	return 0;
}