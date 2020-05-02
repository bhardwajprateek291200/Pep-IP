#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// submitted on https://www.codechef.com/CDMU2015/problems/CDMU03

int func(string s, int n) {
	if (n == 0)
		return 0;

	// precalculation
	vector<int> numbers;
	string operation;
	for (int i = 0; i < n;) {
		if (s[i] == '*' || s[i] == '+') {
			operation += s[i];
			i++;
		}
		else {
			int temp = (s[i] - '0');
			if (i + 1 < n && s[i + 1] != '*' && s[i + 1] != '+') {
				temp = temp * 10 + (s[i + 1] - '0');
				numbers.push_back(temp);
				i += 2;
				continue;
			}
			numbers.push_back(temp);
			i++;
		}
	}

	int l_operation = operation.length();
	int l_numbers = numbers.size();

	// for (int i = 0; i < l_numbers; i++)
	// 	cout << numbers[i] << " ";
	// cout << endl;

	// maintain 2 dp for max count and min count and take a look at the things
	int** max_dp = new int*[l_numbers];
	for (int i = 0; i < l_numbers; i++)
		max_dp[i] = new int[l_numbers]();

	int** min_dp = new int*[l_numbers];
	for (int i = 0; i < l_numbers; i++)
		min_dp[i] = new int[l_numbers]();

	// initailise
	for (int i = 0; i < l_numbers; i++)
		max_dp[i][i] = min_dp[i][i] = numbers[i];

	// algo
	for (int cnt = 1; cnt < l_numbers; cnt++) {
		for (int i = 0; i < l_numbers - cnt; i++) {
			int j = i + cnt;
			int k = i;
			int l = i + 1;
			int left_max, right_max, left_min, right_min;
			int max_cnt = INT_MIN;
			int min_cnt = INT_MAX;
			for (; k < j; k++, l++) {
				left_max = max_dp[i][k];
				right_max = max_dp[l][j];
				left_min = min_dp[i][k];
				right_min = min_dp[l][j];

				if (operation[k] == '*') {
					max_cnt = max(left_max * right_max, max_cnt);
					min_cnt = min(left_min * right_min, min_cnt);
				}
				else {
					max_cnt = max(left_max + right_max, max_cnt);
					min_cnt = min(left_min + right_min, min_cnt);
				}
			}
			max_dp[i][j] = max_cnt;
			min_dp[i][j] = min_cnt;
		}
	}
	int ans = max_dp[0][l_numbers - 1] - min_dp[0][l_numbers - 1];
	for (int i = 0; i < l_numbers; i++) {
		delete [] max_dp[i];
		delete [] min_dp[i];
	}
	delete [] max_dp;
	delete [] min_dp;
	return ans;
}

int32_t main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> s;
		n = s.length();
		cout << func(s, n) << endl;
	}
	return 0;
}