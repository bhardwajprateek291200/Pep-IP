#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
};

Node* newNode(int key)
{
    Node* node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

void topView(struct Node* root)
{
    unordered_map<int, int> ans;
    if (root == NULL)
        return;
    queue<pair<Node*, int>> q;
    unordered_set<int> se;
    int min_level = 0;
    int max_level = 0;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            pair<Node*, int> temp = q.front();
            int ele = temp.first->data;
            int level = temp.second;
            if (se.find(level) == se.end()) {
                min_level = min(min_level, level);
                max_level = max(max_level, level);
                ans[level] = ele;
                se.insert(level);
            }
            q.pop();
            if (temp.first->left != NULL)
                q.push(make_pair(temp.first->left, level - 1));
            if (temp.first->right != NULL)
                q.push(make_pair(temp.first->right, level + 1));
        }
    }
    for (int i = min_level; i <= max_level; i++)
        cout << ans[i] << " ";
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary Tree\n";
    topView(root);
    return 0;
}