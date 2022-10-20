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
    vector<int> arr(n);
    rep(i, 1, n) cin >> arr[i - 1];
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    rep(i, 1, n - 1) {
        rep(j, max(0, i - k), i - 1) {
            dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
        }
    }
    cout << dp[n - 1];
    return 0;
}