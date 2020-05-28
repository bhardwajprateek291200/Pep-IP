#include <bits/stdc++.h>
using namespace std;

class kstack {
private:
	vector<int> arr;  // stores element
	vector<int> next; // stores next free space and if occupied just store the idx of next element
	vector<int> tp;  // stores idx of top element, -1 for empty
	int free;
public:
	kstack(int n, int k) {
		free = 0;
		arr.reserve(n);
		next.reserve(n);
		tp.reserve(k);
		for (int i = 0; i < n; i++)
			next[i] = i + 1;
		next[n - 1] = -1;
		for (int i = 0; i < k; i++)
			tp[i] = -1;
	}

	void push(int x, int id) {
		if (free == -1) {
			cout << "Array is Full." << endl;
			return;
		}
		arr[free] = x;
		int next_available_spot = next[free];
		next[free] = tp[id];
		tp[id] = free;
		free = next_available_spot;
	}

	int top(int id) {
		if (tp[id] == -1)
			cout << "Stack of id: " << id << " is empty." << endl;
		return arr[tp[id]];
	}

	void pop(int id) {
		int temp = tp[id];
		if (temp == -1) {
			cout << "Stack of id: " << id << " is empty." << endl;
			return;
		}
		tp[id] = next[temp];
		next[temp] = free;
		free = temp;
	}

	bool empty(int id) {
		return tp[id] == -1;
	}
};

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;  // size of arr and stacks number
		cin >> n >> k;
		kstack ks = kstack(n, k);
		while (true) {
			int id;
			cin >> id;
			if (id == 1) {
				int x, i;
				cin >> x >> i;
				ks.push(x, i);
			}
			if (id == 2) {
				int i;
				cin >> i;
				ks.pop(i);
			}
			if (id == 3) {
				int i;
				cin >> i;
				cout << ks.top(i) << endl;
			}
			if (id == 4) {
				int i; cin >> i;
				if (ks.empty(i))
					cout << "Empty" << endl;
				else
					cout << "Non-Empty" << endl;
			}
			if (id == 5)
				break;
		}

	}
	return 0;
}