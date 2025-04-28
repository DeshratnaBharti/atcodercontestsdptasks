/***
Problem Statement
There is a grid with 
H horizontal rows and 
W vertical columns. Let 
(i,j) denote the square at the 
i-th row from the top and the 
j-th column from the left.

For each 
i and 
j (
1≤i≤H, 
1≤j≤W), Square 
(i,j) is described by a character 
a 
i,j
​
 . If 
a 
i,j
​
  is ., Square 
(i,j) is an empty square; if 
a 
i,j
​
  is #, Square 
(i,j) is a wall square. It is guaranteed that Squares 
(1,1) and 
(H,W) are empty squares.

Taro will start from Square 
(1,1) and reach 
(H,W) by repeatedly moving right or down to an adjacent empty square.

Find the number of Taro's paths from Square 
(1,1) to 
(H,W). As the answer can be extremely large, find the count modulo 
10 
9
 +7.

Constraints
H and 
W are integers.
2≤H,W≤1000
a 
i,j
​
  is . or #.
Squares 
(1,1) and 
(H,W) are empty squares.
***/


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, m;
vector<vector<int>> dp;

int solve(vector<string>& arr, int i, int j) {
    if (i == n - 1 && j == m - 1) return 1; // Reached destination
    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == '#') return 0; // Out of bounds or blocked
    if (dp[i][j] != -1) return dp[i][j]; // Use memoized result

    long long down = solve(arr, i + 1, j);
    long long right = solve(arr, i, j + 1);

    return dp[i][j] = (down + right) % MOD; // Store result
}

int main() {
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    dp.assign(n, vector<int>(m, -1)); // Initialize DP table
    cout << solve(arr, 0, 0) << endl;

    return 0;
}
