#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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
    unordered_map<int, vector<int>> edge;
    rep(i, 0, n - 2) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    unordered_map<int, vector<int>> edges;
    unordered_set<int> s;
    queue<int> qq;
    qq.push(1);
    while (!qq.empty()) {
        int temp = qq.front();
        s.insert(temp);
        for (auto& a : edge[temp]) {
            if (!s.count(a)) {
                edges[temp].push_back(a);
                qq.push(a);
            }
        }
        qq.pop();
    }
    /*for (auto& a : edges) {
        cout << a.first << " : ";
        for (auto& i : a.second)  cout << i << " ";
        cout << "\n";
    }*/
    vector<int> val(n);
    rep(i, 0, n - 1) cin >> val[i];
    //建子到父的unordered_map
    unordered_map<int, int> mp;
    vector<int> outdegrees(n + 1);
    for (auto& k : edges) {
        outdegrees[k.first]+= k.second.size();
        for (auto& a : k.second) {
            mp[a] = k.first;
        }
    }
    vector < pair < ll, ll >> operations(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (outdegrees[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            int temp = q.front();
            q.pop();
            ll pre = val[temp-1];
            //cout << temp << " " << pre << "\n";
            for (auto& a : edges[temp]) {
                operations[temp].first = max(operations[a].first, operations[temp].first);
                operations[temp].second = max(operations[a].second, operations[temp].second);
            }
            pre += operations[temp].first;
            pre -= operations[temp].second;
            //cout << temp << " " << operations[temp].first << " " << operations[temp].second<< "\n";

            if (pre > 0) operations[temp].second += pre;
            if (pre < 0) operations[temp].first -= pre;
            outdegrees[mp[temp]]--;
            if (outdegrees[mp[temp]] == 0) q.push(mp[temp]);
        }
    }
    cout << operations[1].first + operations[1].second;
    return 0;
}
