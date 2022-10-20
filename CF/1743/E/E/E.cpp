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
    ll p1, t1, p2, t2,h,s;
    cin >> p1 >> t1 >> p2 >> t2>>h>>s;
    vector<ll> dp(h + 1);
    dp[0] = 0;
    //任何一个dp[i]一定是处于以下三种状态之一
    //1: 1刚开炮
    //2: 2刚开炮
    //3: 1&2刚同时开炮
    rep(i, 1, h) {
        dp[i] = min(dp[max(0ll, i - (p1 - s))] + t1, dp[max(0ll, i - (p2 - s))] + t2);
        //判断同时开炮？
        //每次开炮的最低贡献是1 所以对于dp[i]来说 1/2最多开i次炮？
        rep(j, 1, i) {
            //1的用时有盈余
            //开了j次1
            if (t1 * j >= t2) {
                ll dmg = (j - 1) * (p1 - s) + (t1 * j / t2 - 1) * (p2 - s) + (p1 + p2 - s);
                dp[i] = min(dp[i], dp[max(0ll, i - dmg)] + t1 * j);
            }
            //2的用时有盈余
            //开了j次2                                              
            if (t2 * j >= t1) {
                ll dmg = (j - 1) * (p2 - s) + (t2 * j / t1 - 1) * (p1 - s) + (p1 + p2 - s);
                dp[i] = min(dp[i], dp[max(0ll, i - dmg)] + t2 * j);
            }
        }
    }
    cout << dp[h];
    return 0;
}
