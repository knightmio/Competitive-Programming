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
    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    rep(i, 0, n - 1) cin >> v[i];
    sort(v.begin(), v.end());
    int res = 0;
    ll temp = 0;
    int idx = 0;
    while (idx < n && temp <= l) {
        res++;
        temp += v[idx];
        idx++;
    }
    if (temp > l) res--;
    cout << res;
    return 0;
}
