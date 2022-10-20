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
    vector<int> arr(n);
    rep(i, 1, n) cin >> arr[i - 1];
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    rep(i, 2, n - 1) dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    cout << dp[n - 1];
    return 0;
}
