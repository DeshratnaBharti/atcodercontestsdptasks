/***
Problem Statement
There are 
N items, numbered 
1,2,…,N. For each 
i (
1≤i≤N), Item 
i has a weight of 
w 
i
​
  and a value of 
v 
i
​
 .

Taro has decided to choose some of the 
N items and carry them home in a knapsack. The capacity of the knapsack is 
W, which means that the sum of the weights of items taken must be at most 
W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10 
5
 
1≤w 
i
​
 ≤W
1≤v 
i
​
 ≤10 
9
 
Input
Input is given from Standard Input in the following format:

N 
W
w 
1
​
  
v 
1
​
 
w 
2
​
  
v 
2
​
 
:
w 
N
​
  
v 
N
​
 
Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1
Copy
3 8
3 30
4 50
5 60
**/

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long f(vector<pair<int, int>> &vec, int idx, int c) {
    if (idx == vec.size()) return 0;
    if (dp[idx][c] != -1) return dp[idx][c];

    long long ans = f(vec, idx + 1, c); // Move to next item

    if (vec[idx].first <= c) { // Check weight constraint
        ans = max(ans, vec[idx].second + f(vec, idx + 1, c - vec[idx].first));
    }

    return dp[idx][c] = ans;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;//{w,v}
    }

    // Correctly initialize dp based on input size
    dp.assign(n + 1, vector<long long>(c + 1, -1));

    cout << f(vec, 0, c) << endl;

    return 0;
}
