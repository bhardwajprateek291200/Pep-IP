#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

struct TreeNode {
	int data;
	TreeNode *left, *right;

	TreeNode(int x) {
		data = x;
		left = right = NULL;
	}
};

int helper(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL || root2 == NULL)
		return 0;
	int ans = (root1->data * root2->data) % MOD;
	int temp1 = helper(root1->right, root2->left);
	int temp2 = helper(root1->left, root2->right);
	return (ans + temp1 + temp2) % MOD;
}

int imageMultiplication(TreeNode *root) {
	if (root == NULL)
		return 0;
	int ans = 0;
	ans += (root->data * root->data) % MOD;
	ans += helper(root->left, root->right);
	ans %= MOD;
	return ans;
}

int main()
{
	int t;
	TreeNode *child;
	cin >> t;
	while (t--)
	{
		map<int, TreeNode*> m;
		int n;
		cin >> n;
		TreeNode *root = NULL;
		while (n--)
		{
			TreeNode *parent;
			char lr;
			int n1, n2;
			cin >> n1 >> n2 >> lr;

			if (m.find(n1) == m.end())
			{
				parent = new TreeNode(n1);
				m[n1] = parent;
				if (root == NULL) root = parent;
			}
			else parent = m[n1];

			child = new TreeNode(n2);
			if (lr == 'L') parent->left = child;
			else parent->right = child;
			m[n2]  = child;
		}

		cout << imageMultiplication(root) % MOD << endl;
	}
}