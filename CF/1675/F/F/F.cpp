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
        int n, k;
        cin >> n >> k;
        int x, y;
        cin >> x >> y;
        vector<int> nodes(k);
        unordered_map<int, vector<int>> edge;
        rep(j, 0, k - 1) {
            cin >> nodes[j];
        }
        rep(j, 0, n - 2) {
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        vector<int> vis(n+1);
        unordered_map<int, vector<int>> path;

        function<void(int,int)> dfs = [&](int cur, int fa) {
            for (auto v : edge[cur]) {
                if (v == fa) continue;
                dfs(v, cur);
                path[v].push_back(cur);
            }
        };

        function<int(int, int)> count = [&](int cur, int sum)->int {
            if (vis[cur]) return sum;
            vis[cur] = 1;
            for (auto v : path[cur]) {
                return count(v, sum + 1);
            }
        };

        int res = 0;
        dfs(x, -1);
        vis[x] = 1;
        res += count(y, 0);
        rep(j, 0, k - 1) {
            res += count(nodes[j], 0) * 2;
        }
        cout << res << "\n";
    }
}
