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
        int n, a, b;
        cin >> n >> a >> b;
        unordered_map<int, vector<int>> mp;
        map<pair<int, int>, ll> weight;
        rep(j, 0, n - 2) {
            ll x, y, z;
            cin >> x >> y >> z;
            mp[x].push_back(y);
            mp[y].push_back(x);
            weight[{x,y}] = z;
            weight[{y, x}] = z;
        }
        set<ll> s;
        queue<vector<ll>> q;
        q.push({b,-1,0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto& e : mp[p[0]]) {
                if (e == p[1]) continue;
                q.push({ e,p[0],p[2] ^ weight[{e,p[0]}] });
                s.insert(p[2] ^ weight[{e, p[0]}]);
            }
        }
        bool temp = false;
        q.push({ a,-1,0 });
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto& e : mp[p[0]]) {
                if (e == p[1]) continue;
                long long next = (p[2] ^ weight[{e, p[0]}]);
                if (e == b) {
                    if (next == 0) {
                        temp = true;
                        break;
                    }
                    else {
                        continue;
                    }
                }
                if (s.count(next)) {
                    temp = true;
                    break;
                }
                q.push({ e,p[0],next });
                
            }
        }
        if (s.count(0)) temp = true;
        if (temp) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
