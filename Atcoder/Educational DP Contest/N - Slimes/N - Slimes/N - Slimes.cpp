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
    rep(i, 0, n - 1)cin >> input[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LLONG_MAX));
    vector<ll> pref(n + 1);
    rep(i, 1, n) {
        pref[i] = pref[i - 1] + input[i - 1];
        dp[i][i] = 0;
    }
    for (int len = 1; len < n; len++) {
        for (int start = 1; start + len <= n; start++) {
            ll temp = LLONG_MAX;
            for (int i = start; i < start + len; i++) {
                //cout << dp[i][i] << " ? " << dp[i + 1][start + len] << "\n";
                temp = min(temp, dp[start][i] + dp[i + 1][start + len]);
            }
            dp[start][start + len] = temp + pref[start + len] - pref[start - 1];
            //cout << start << " " << start + len << " " << dp[start][start + len] << " " << temp << "\n";

        }
    }
    cout << dp[1][n];
}
