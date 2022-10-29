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
        int n;
        cin >> n;
        priority_queue<pair<int, int>> pq;
        ll len = 0;
        rep(j, 0, n - 1) {
            int a, b;
            cin >> a >> b;
            if (a < b) swap(a,b);
            pq.push({ a,b });
            len += b;
        }
        ll res = 9223372036854775807;
        int limit = 0;
        while (!pq.empty()) {
            if (pq.top().first < limit) break;
            res = min(res, 2ll * len + 2ll * pq.top().first);
            limit = max(limit, pq.top().second);
            len -= pq.top().second;
            len += pq.top().first;
            pq.pop();
        }
        cout << res << "\n";
    }
}