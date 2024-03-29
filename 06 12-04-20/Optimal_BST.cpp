#include <bits/stdc++.h>
using namespace std;

// prefix sum
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];

    /* cost[i][j] = Optimal cost of binary search tree
    that can be formed from keys[i] to keys[j].
    cost[0][n-1] will store the resultant cost */

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++)  {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +  ((r < j) ? cost[r + 1][j] : 0) +  sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    int keys[n];
    int freq[n];
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    cout << optimalSearchTree(keys, freq, n);
    return 0;
}