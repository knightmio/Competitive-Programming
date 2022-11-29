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
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
        vector<int> arr(n);
        rep(j, 0, n - 1) cin >> arr[j];
        vector<int> ones(n);
        vector<int> zeros(n);
        rep(j, 1, n - 1) {
            ones[j] = ones[j - 1];
            if (arr[j - 1] == 1) ones[j]++;
        }
        for (int j = n - 2; j >= 0; j--) {
            zeros[j] = zeros[j + 1];
            if (arr[j + 1] == 0) zeros[j]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) res += zeros[i];
        }
        int ans = res;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                ans = max(ans, res - ones[i] + zeros[i]);
            }
            else {
                ans = max(ans, res + ones[i] - zeros[i]);
            }
        }
        cout << ans << "\n";
    }
}

