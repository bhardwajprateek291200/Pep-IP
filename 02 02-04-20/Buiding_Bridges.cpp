#include <bits/stdc++.h>
using namespace std;


// submitted on https://www.spoj.com/problems/BRIDGE/

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)
		return 0;
	int* arr = new int[n]();
	arr[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		int maxi = 0;
		arr[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] >= nums[i]) {
				arr[i] = max(arr[j] + 1, arr[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > ans)
			ans = arr[i];
	}
	delete [] arr;
	return ans;
}

long func(int n, vector<pair<int, int> > arr) {
	if (n <= 1)
		return n;
	sort(arr.begin(), arr.end());
	// for (int i = 0; i < n; i++) {
	// 	cout << v[i].first << " " << v[i].second << endl;
	// }

	//LIS
	vector<int> nums;
	for (int i = 0; i < n; i++)
		nums.push_back(arr[i].second);
	return lengthOfLIS(nums);

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++) {
			int temp; cin >> temp;
			v.push_back(make_pair(temp, temp));
		}
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v[i].second = temp;
		}
		cout << func(n, v) << endl;
		v.clear();
	}
	return 0;
}