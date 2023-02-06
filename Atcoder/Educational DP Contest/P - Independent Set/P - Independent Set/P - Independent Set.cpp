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
    int n;
    cin >> n;
    unordered_map<int, vector<int>> mp;
    rep(i, 0, n - 2) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);

    }

    function<pair<ll, ll>(int, int)> dfs = [&](int x, int fa)->pair<ll, ll> {
        //cout << x << " " << fa << "\n";
        ll w = 1;
        ll b = 1;
        for (auto& a : mp[x]) {
            if (a == fa) continue;
            auto next = dfs(a, x);
            w *= (next.first + next.second);
            b *= next.first;
            w %= 1000000007;
            b %= 1000000007;
        }
        return { w,b };
    };

    auto a = dfs(1, 0);
    long long res = a.first + a.second;
    cout << res % 1000000007;
    return 0;
}
