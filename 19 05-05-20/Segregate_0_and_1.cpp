#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int n) {
	int type0 = 0;
	int type1 = n - 1;
	while (type0 < type1)
	{
		if (arr[type0] == 1)
		{
			swap(arr[type0],  arr[type1]);
			type1--;
		}
		else
			type0++;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		func(arr, n);
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		delete [] arr;
	}
	return 0;
}