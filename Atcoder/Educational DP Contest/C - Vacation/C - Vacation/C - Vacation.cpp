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
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    rep(i, 0, n - 1) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[3] = { 0 };
    rep(i, 0, n - 1) {
        int aa = max(dp[1], dp[2]) + a[i];
        int bb = max(dp[0], dp[2]) + b[i];
        int cc = max(dp[1], dp[0]) + c[i];
        dp[0] = aa;
        dp[1] = bb;
        dp[2] = cc;
    }
    cout << max({ dp[0],dp[1] ,dp[2] });
    return 0;
}
