#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
const int MAXN = 5010;
ll a[MAXN], b[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll t = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]), t += a[i] * b[i];
    ll res = t;
    for (int i = 1; i <= n; i++) dp[i][i] = t, dp[i + 1][i] = t;//初始化
    rep(len, 2, n) {//长度
        rep(i, 1, n+1-len) {//左端点
            int j = len + i - 1;
            dp[i][j] = dp[i + 1][j - 1] - a[i] * b[i] - a[j] * b[j] + a[i] * b[j] + a[j] * b[i];
            res = max(res, dp[i][j]);
        }
    }
    //for (int i = 1; i <= n; i++){
    //    for (int j = i; j <= n; j++) {
    //        if (res < dp[i][j]) cout << i << " " << j << "\n";
    //        res = max(res, dp[i][j]);
    //    }
    //}
    cout << res;
    //中心扩散法 遍历每个起点 距离可以是奇数 也可以是偶数 不断更新最大difference
    //然后返回原来的和+最大difference
    //long long max_diff = LONG_MIN;
    //for (int i = 0; i < n - 1; i++) {
    //    int l = i - 1, r = i + 1;
    //    long long diff = 0;
    //    while (l >= 0 && r < n) {
    //        diff += a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
    //        max_diff = max(max_diff, diff);
    //        l--; r++;
    //    }
    //    l = i, r = i + 1;
    //    diff = 0;
    //    while (l >= 0 && r < n) {
    //        diff += a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
    //        max_diff = max(max_diff, diff);
    //        l--; r++;
    //    }
    //}
    //cout << ans + max((long long)0, max_diff) << endl;
    return 0;
}