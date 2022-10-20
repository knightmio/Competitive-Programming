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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int>(k + 1, INT_MAX / 2));
    vector<vector<int>> sum(n, vector<int>(n, -1));
    vector<int> height(n);
    rep(i, 0, n - 1) cin >> height[i];
    dp[0][0] = 0;
    rep(i, 0, n - 1) {
        rep(j, i, n - 1) {
            int temp = INT_MAX;
            rep(kk, i, j) {
                int cur = 0;
                rep(kkk, i, j) {
                    cur += abs(height[kkk] - height[kk]);
                }
                temp = min(temp, cur);
            }
            sum[i][j] = temp;
        }
    }
    rep(i, 1, n) {
        rep(j, 1, k) {
            if (j == 1) {
                dp[i][j] = sum[0][i - 1];
            }else{
                rep(kk, 2, i) {
                    dp[i][j] = min(dp[i][j], dp[kk - 1][j - 1] + sum[kk - 1][i - 1]);
                }
            }
        }
    }
    cout << dp[n][k];
    return 0;
}
