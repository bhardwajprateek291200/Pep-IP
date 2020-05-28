#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int val;
	char ch;
	node* left;
	node* right;
	node(int v, int c) {
		val = v;
		ch = c;
		left = NULL;
		right = NULL;
	}
};

class comp {
public:
	bool operator()(node* a, node* b) {
		return a->val > b->val;
	}
};

void traversal(node* root, string s = "") {
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL) {
		cout << root->ch << "--->" << s << endl;
		return;
	}
	traversal(root->left, s + "0");
	traversal(root->right, s + "1");
}

void func(vector<char> v, int n) {
	priority_queue<node* , vector<node*>, comp> pq;
	unordered_map<char, int> m;
	for (int i = 0; i < n; i++)
		m[v[i]]++;
	for (auto x : m)
		pq.push(new node(x.second, x.first));

	while (pq.size() > 1) {
		node* temp1 = pq.top();
		pq.pop();
		node* temp2 = pq.top();
		pq.pop();
		node* nn = new node(temp1->val + temp2->val, '0');
		nn->left = temp1;
		nn->right = temp2;
		pq.push(nn);
	}

	node* root = pq.top();
	pq.pop();

	//traverse
	traversal(root);

}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<char> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		func(v, n);
	}
	return 0;
}