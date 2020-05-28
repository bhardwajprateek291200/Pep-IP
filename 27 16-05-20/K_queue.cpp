#include <bits/stdc++.h>
using namespace std;

class kqueue {
private:
	vector<int> arr;  // stores element
	vector<int> next; // stores next free space and if occupied just store the idx of next element
	vector<int> top;  // stores idx of top element, -1 for empty
	vector<int> end; // stores end idx
	int free;
public:
	kqueue(int n, int k) {
		free = 0;
		arr.reserve(n);
		next.reserve(n);
		top.reserve(k);
		end.reserve(k);
		for (int i = 0; i < n; i++)
			next[i] = i + 1;
		next[n - 1] = -1;
		for (int i = 0; i < k; i++)
			top[i] = -1;
		for (int i = 0; i < k; i++)
			end[i] = -1;
	}

	void push(int x, int id) {
		if (free == -1) {
			cout << "Array is Full." << endl;
			return;
		}
		arr[free] = x;
		int next_available_spot = next[free];
		next[free] = -1;
		int temp = top[id];
		if (temp == -1) {
			end[id] = free;
			top[id] = end[id];
		}
		else {
			temp = end[id];
			next[temp] = free;
			end[id] = free;
		}
		free = next_available_spot;
	}

	int front(int id) {
		if (top[id] == -1)
			cout << "Queue of id: " << id << " is empty." << endl;
		return arr[top[id]];
	}

	void pop(int id) {
		int temp = top[id];
		if (temp == -1) {
			cout << "Queue of id: " << id << " is empty." << endl;
			return;
		}
		top[id] = next[temp];
		next[temp] = free;
		free = temp;
	}

	bool empty(int id) {
		return top[id] == -1;
	}
};

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;  // size of arr and stacks number
		cin >> n >> k;
		kqueue ks = kqueue(n, k);
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
				cout << ks.front(i) << endl;
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