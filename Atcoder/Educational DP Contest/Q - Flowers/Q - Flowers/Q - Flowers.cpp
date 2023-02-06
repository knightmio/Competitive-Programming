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
vector<ll> ma;

void modify(int o, int l, int r, int i, ll val) {
    if (l == r) {
        ma[o] = val;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) modify(o * 2, l, m, i, val);
    else modify(o * 2 + 1, m + 1, r, i, val);
    ma[o] = std::max(ma[o * 2], ma[o * 2 + 1]);
}

// 返回区间 [L,R] 内的最大值
ll query(int o, int l, int r, int L, int R) { // L 和 R 在整个递归过程中均不变，将其大写，视作常量
    if (L <= l && r <= R) return ma[o];
    ll res = 0;
    int m = (l + r) / 2;
    if (L <= m) res = query(o * 2, l, m, L, R);
    if (R > m) res = std::max(res, query(o * 2 + 1, m + 1, r, L, R));
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> b(n);
    rep(i, 0, n - 1) cin >> h[i];
    rep(i, 0, n - 1) cin >> b[i];
    vector<int> temp = h;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> mp;
    rep(i, 0, n - 1) mp[temp[i]] = i + 1;
    ma.resize(n * 4);
    ll res = b[0];
    modify(1, 1, n, mp[h[0]], b[0]);
    rep(i, 1, n - 1) {
        ll cur = query(1, 1, n, 1, mp[h[i]]);
        res = max(res, cur + b[i]);
        //cout << i << " " << mp[h[i]]<<" " << cur <<" " << res <<  "\n";

        modify(1, 1, n, mp[h[i]], cur + b[i]);
        
        //cout << i << " " << mp[h[i]] << " "<< res << " "  << query(1, 1, n, mp[h[i]], mp[h[i]]) << "\n";
    }
    cout << res;
}