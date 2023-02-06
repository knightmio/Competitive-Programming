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
    int n;
    cin >> n;
    vector<double> rate(n);
    rep(i, 0, n - 1) cin >> rate[i];

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    rep(i, 1, n) {
        rep(j, 0, i) {
            if (j - 1 >= 0) dp[j][i - j] += dp[j - 1][i - j] * rate[i - 1];
            if (i - j - 1 >= 0) dp[j][i - j] += dp[j][i - j-1] * (1-rate[i - 1]);
        }
    }
    double res = 0;
    rep(i, n/2+1, n) res += dp[i][n - i];
    cout << setprecision(20) << res;
    return 0;
}
