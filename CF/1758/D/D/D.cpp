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
        ll diff = 1ll*(n + 10) * (n + 10);
        ll ma = diff - 1ll * (n+10 + 11) * (n - 1) / 2;
        ll mi = diff - (n + 10) - 1ll * (1 + n-2) * (n - 2) / 2;
        int l;
        for (int i = ma; i <= mi; i++) {
            if (i % n == 0) {
                l = i / n;
                break;
            }
        }
        vector<int> res;
        res.push_back(l);
        res.push_back(l+10);

    }
}
