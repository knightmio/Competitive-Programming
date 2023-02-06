#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    string s; cin >> s;
    string t; cin >> t;
    int n1 = s.length();
    int n2 = t.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    //最长公共子序列问题
    //典型二维dp?
    //dp[i][j]表示 s的前i个字符和t的前j个字符 最多能有多少个一样的？
    rep(i, 1, n1) {
        rep(j, 1, n2) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
            }
        }
    }
    //然后逆推字符串吗
    string res = "";
    while (dp[n1][n2] > 0) {
        while (n1 > 0 && dp[n1 - 1][n2] == dp[n1][n2]) n1--;
        while (n2 > 0 && dp[n1][n2-1] == dp[n1][n2]) n2--;
        res = s[n1 - 1] + res;
        n1--;
        n2--;
    }
    cout << res;
    return 0;
}
