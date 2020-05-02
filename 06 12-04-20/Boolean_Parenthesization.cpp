#include <bits/stdc++.h>
using namespace std;
#define Mod 1003

int func(string s, int n) {
	if (n == 0)
		return 0;

	// precalculation
	string boolean;
	string operation;
	for (int i = 0; i < n; i++) {
		if (i & 1)
			operation += s[i];
		else
			boolean += s[i];
	}

	int l_operation = operation.length();
	int l_boolean = boolean.length();

	// maintain 2 dp for true count and false count and take a look at the things
	int** true_dp = new int*[l_boolean];
	for (int i = 0; i < l_boolean; i++)
		true_dp[i] = new int[l_boolean]();

	int** false_dp = new int*[l_boolean];
	for (int i = 0; i < l_boolean; i++)
		false_dp[i] = new int[l_boolean]();

	// initailise
	for (int i = 0; i < l_boolean; i++) {
		if (boolean[i] == 'T') {
			true_dp[i][i] = 1;
			false_dp[i][i] = 0;
		}
		else {
			true_dp[i][i] = 0;
			false_dp[i][i] = 1;
		}
	}

	// algo
	for (int cnt = 1; cnt < l_boolean; cnt++) {
		for (int i = 0; i < l_boolean - cnt; i++) {
			int j = i + cnt;
			int k = i;
			int l = i + 1;
			int left_true, right_true, left_false, right_false;
			int true_cnt = 0;
			int false_cnt = 0;
			for (; k < j; k++, l++) {
				left_true = true_dp[i][k];
				right_true = true_dp[l][j];
				left_false = false_dp[i][k];
				right_false = false_dp[l][j];

				if (operation[k] == '|') {
					true_cnt += ((left_true * right_true) % Mod + ((left_true * right_false) % Mod + (right_true * left_false) % Mod) % Mod) % Mod;
					false_cnt += (left_false * right_false) % Mod;
				}
				else if (operation[k] == '&') {
					true_cnt += (left_true * right_true) % Mod;
					false_cnt += ((left_false * right_false) % Mod + ((left_false * right_true) % Mod + (right_false * left_true) % Mod) % Mod) % Mod;
				}
				else {
					true_cnt += ((left_true * right_false) % Mod + (right_true * left_false) % Mod) % Mod;
					false_cnt += ((left_true * right_true) % Mod + (right_false * left_false) % Mod) % Mod;
				}
				true_cnt %= Mod;
				false_cnt %= Mod;
			}
			true_dp[i][j] = true_cnt;
			false_dp[i][j] = false_cnt;
		}
	}
	int ans = true_dp[0][l_boolean - 1];
	for (int i = 0; i < l_boolean; i++) {
		delete [] true_dp[i];
		delete [] false_dp[i];
	}
	delete [] true_dp;
	delete [] false_dp;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << func(s, n) << endl;
	}
	return 0;
}