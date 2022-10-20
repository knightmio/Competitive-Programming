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
    int n, m;
    cin >> n >> m;
    //拿并查集做
    int fa[101];
    iota(fa, fa + 101, 0);
    function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };
    function<void(int, int)> merge = [&](int x, int y) {
        int a = find(x);//寻找根节点
        int b = find(y);
        if (a != b)//如果根节点不一样、、则需要合并，否则不需要
            fa[a] = b;
    };
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> edges(n + 1, vector<int>(n + 1));
    
    function<int(int, int, int, int)> dfs = [&](int cur, int pre, int goal, int cost) -> int {
        if (cur == goal) return cost;
        int res = INT_MAX;
        for (auto& i : mp[cur]) {
            if (i == pre) continue;
            res = min(res, dfs(i, cur, goal, cost+edges[cur][i]));
        }
        return res;
    };

    rep(i, 0, m - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (find(a) != find(b)) {
            merge(a, b);
            mp[a].push_back(b);
            mp[b].push_back(a);
            edges[a][b] = c;
            edges[b][a] = -c;
        }
        else {
            //判断连通块是否成立？
            int len = dfs(a, -1, b, 0);
            //cout << a << " " << len << "\n";
            if (len != c) {
                cout << "wake up";
                return 0;
            }
            edges[a][b] = c;
            edges[b][a] = -c;
        }
    }
    cout << "we live in a society";
    return 0;
}
