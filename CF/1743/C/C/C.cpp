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
    int t;
    cin >> t;
    rep(i, 0, t-1) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> lid(n);
        rep(j, 0, n - 1) lid[j] = s[j]-'0';
        vector<int> val(n);
        rep(j, 0, n - 1) cin >> val[j];
        vector<vector<ll>> dp(n, vector<ll>(2));
        if (lid[0] == 1) {
            dp[0][0] = val[0];
            dp[0][1] = INT_MIN;
        }
        rep(j, 1, n - 1) {
            if (lid[j] == 0) { 
                dp[j][0] = dp[j - 1][0];
                dp[j][1] = dp[j - 1][1];
            }else{
                if (lid[j - 1] == 0) {
                    dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]) + val[j];
                    dp[j][1] = max(dp[j - 1][0], dp[j - 1][1]) + val[j-1];
                }
                else {
                    dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]) + val[j];
                    dp[j][1] = dp[j - 1][1] + val[j - 1];
                }
            }
        }
        cout << max(dp[n-1][0], dp[n - 1][1]) << "\n";
    }
    return 0;
}
