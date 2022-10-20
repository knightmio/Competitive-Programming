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
    int n, w;
    cin >> n >> w;
    vector<int> num(n);
    vector<int> weight(n);
    rep(i, 0, n - 1) {
        cin >> num[i] >> weight[i];
    }
    //背包问题要怎么做来着？
    //二维dp 前i个物品里面重量最多为j的情况下 最大的收益是多少？
    //滚动数组
    long long res = 0;
    vector<long long> dp(w + 1, 0);
    rep(i, 1, n) {
        for (int j = w; j >= num[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - num[i - 1]] + weight[i - 1]);
            res = max(res, dp[j]);
        }
    }
    cout << res;
    return 0;
}
