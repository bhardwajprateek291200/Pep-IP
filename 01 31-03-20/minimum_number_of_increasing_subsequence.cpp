#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n) {
	// applying LIS in reverse order
	vector<int> nums;
	for (int i = n - 1; i >= 0; i--)
		nums.push_back(arr[i]);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (v.size() == 0)
			v.push_back(nums[i]);
		else
		{
			int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
			if (idx != v.size())
				v[idx] = nums[i];
			else
				v.push_back(nums[i]);
		}
	}
	n = v.size();
	v.clear();
	nums.clear();
	return n;
}

int main() {
	int n;
	int arr[1000005];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//same as obtaining longest decreasing subsequence
	cout << func(arr, n) << endl;
	return 0;
}