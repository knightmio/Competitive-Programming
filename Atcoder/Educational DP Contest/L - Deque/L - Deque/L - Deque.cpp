#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    rep(i, 0, n - 1) cin >> input[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    rep(i, 1, n) {
        dp[i][i] = input[i - 1];
    }
    rep(j, 1, n-1) {
        rep(i, 1, n) {
            if (j + i > n) break;
            dp[i][i + j] = max(input[i - 1]- dp[i + 1][i + j], input[i + j - 1]- dp[i][i + j - 1]);
        }
    }
    cout << dp[1][n];
}
