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
    //记忆化dfs？
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
    string p0 = "What are you doing while sending \"";
    string p1 = "\"? Are you busy? Will you send \"";
    string p2 = "\"?";
    ll l0 = (ll)p0.size();
    ll l1 = (ll)p1.size();
    ll l2 = (ll)p2.size();
    vector<ll> sz{ (ll)s.size() };
    //初始化size 最多1e18
    while (sz[sz.size() - 1] < 1e18) {
        sz.push_back(sz[sz.size() - 1] * 2 + l0 + l1 + l2);
    }
    int n;
    cin >> n;
    ll a, b;
    function<char(ll,ll)> dfs = [&](ll n, ll k) -> char {
        k--;
        while (true) {
            if (n < sz.size() && k >= sz[n]) return '.';
            if (n == 0) return s[k];
            if (k < l0) return p0[k];
            k -= l0;
            //输出由上一个状态决定
            n--;
            if (n >= sz.size() || k < sz[n]) continue;
            k -= sz[n];
            if (k < l1) return p1[k];
            k -= l1;
            if (k < sz[n]) continue;
            k -= sz[n];
            return p2[k];
        }
        return '.';
    };


    rep(i, 0, n - 1) {
        cin >> a >> b;
        cout << dfs(a, b);
    }
    return 0;
}
