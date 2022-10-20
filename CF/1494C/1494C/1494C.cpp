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
    int t;
    cin >> t;
    int m, n;
    rep(i, 0, t - 1) {
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        rep(j, 0, n - 1) cin >> a[j];
        rep(j, 0, m - 1) cin >> b[j];
    }
    return 0;
}
