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

const int N = 3e3 + 10, mod = 1e9 + 7;
int f[N][N], n;
char c[N];
int main() {
    cin >> n;
    rep(i, 1, n - 1) cin >> c[i];
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (c[i - 1] == '<')
            for (int j = 2; j <= i; ++j) f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % mod;
        else
            for (int j = i - 1; j; --j) f[i][j] = (f[i][j + 1] + f[i - 1][j]) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + f[n][i]) % mod;
    cout << f[2][3] << "?\n";
    cout << ans;
}