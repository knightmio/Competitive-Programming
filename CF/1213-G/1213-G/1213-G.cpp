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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n-1);
    rep(i, 0, n - 2) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = { a,b,c };
    }
    vector<int> queries(m);
    rep(i, 0, m - 1) cin >> queries[i];
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    vector<int> init(n+1, 1);
    //int size = *max_element(queries.begin(), queries.end());
    vector<long long> num(2e5 + 10);
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };
    function<void(int, int)> merge = [&](int x, int y) {
        int a = find(x);//寻找根节点
        int b = find(y);
        if (a != b)//如果根节点不一样、、则需要合并，否则不需要
            fa[a] = b;
    };

    rep(i, 0, n - 2) {
        //cout << i << "\n";
        //num[edges[i][2]]++;
        int ru = find(edges[i][0]), rv = find(edges[i][1]); 
        /*cout << i << " " << init[ru] << " " << init[rv] << "\n";
        cout << ru << " " << rv << "\n";*/
        num[edges[i][2]] += 1ll*init[ru] * init[rv];
        merge(ru,rv);
        int temp = init[ru];
        init[ru] += init[rv];
        init[rv] += temp;
    }
    for (int i = 2; i < 2e5+1; i++) {
        num[i] += num[i - 1];
    }
    for (auto& a : queries) cout << num[a] << ' ';
    return 0;
}
