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

    long long res = 0;
    //本质不还是一样的吗
    //滚动数组节约空间
    //啊 因为重量的上限变成了1e9 所以不能枚举重量
    //那要枚举数量吗 - 枚举价值
    //最多有100个*10^3 = 10^5个价值
    vector<long long> dp(n*1000+1, INT_MAX/2);
    dp[0] = 0;
    rep(i, 1, n) {
        for (int j = i * 1000; j >= weight[i - 1]; j--) {
            //cout << j << " ";
            dp[j] = min(dp[j], dp[j - weight[i - 1]] + num[i - 1]);
        }
    }
    for (int j = n * 1000 ; j >= 0; j--) {
        if (dp[j] <= w) {
            cout << j;
            break;
        }
    }
    return 0;
}
