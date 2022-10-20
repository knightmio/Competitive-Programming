#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
//还是二维数组适合老子
int const maxn = 1e5 + 5, maxk = 450;
int a[maxn], dp[maxn][maxk];
int inf = 1e9 + 7;
//前缀和
ll pref[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        int k = 0;
        //k最大值
        while (k * (k + 1) / 2 <= n) k++;
        
        for (int j = 0; j < k; ++j) {
            dp[n + 1][j] = -inf;
        }
        dp[n + 1][0] = inf;
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = dp[i + 1][j];
                //需要满足以下条件
                //1：当前判断的长度大于0 - 否则没有意义
                //2：不超边界
                //3：当前和（通过前缀和计算）满足条件
                if (j && i + j - 1 <= n && pref[i + j - 1] - pref[i - 1] < dp[i + j][j - 1]) {
                    dp[i][j] = max(dp[i][j], (int)(pref[i + j - 1] - pref[i - 1]));
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < k; ++j) {
            //大于0说明有成立的组合
            if (dp[1][j] > 0) ans = j;
        }
        cout << ans << '\n';
    }
    return 0;
}