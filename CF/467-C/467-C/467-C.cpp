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
    ll int n, m, a, b, cnt = 0, k;
    string s, res;



    cin >> n >> m >> k;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) { cin >> v[i]; v[i] += v[i - 1]; }

    //怎么样滚动数组优化？
    vector<ll> dp(n + 1,0);
    vector<ll> pre(n + 1,0);


    for (int i = 1; i <= k; i++)
    {
        for (int j = i * m; j <= n; j++)dp[j] = max(dp[j - 1], pre[j - m] + v[j] - v[j - m]);
        pre = dp;
    }

    cout << dp[n] << endl;

    return 0;

}
