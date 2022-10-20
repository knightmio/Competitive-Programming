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
const int N = 200005;
//到达每个数的总操作次数
int num[N];

//这个数被达到的次数
int cnt[N];
bool st[N];
int main()
{
    //暴力+bfs
    //统计每个数字能到达的所有数字
    int n;
    cin >> n;
    vector<int> arr(n);
    function<void(int)> bfs = [&](int x) {
        memset(st, 0, sizeof st);
        queue<pair<int, int>> q;
        
        q.push({ x,0 });
        ++cnt[x];
        st[x] = true;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            if ((x << 1) <= 1e5 && !st[x << 1]) {
                st[x << 1] = true;
                ++cnt[x << 1];
                q.push({ x << 1, y + 1 });
                num[x << 1] += y + 1;
            }
            if ((x >> 1) >= 1 && !st[x >> 1]) {
                st[x >> 1] = true;
                ++cnt[x >> 1];
                q.push({ x >> 1, y + 1 });
                num[x >> 1] += y + 1;
            }
        }
    };
    rep(i, 0, n - 1) {
        cin >> arr[i];
        bfs(arr[i]);
    }
    //遍历所有cnt找最小值？
    int res = INT_MAX;
    for (int i = 1; i < N; i++) {
        if (cnt[i] == n) res = min(res, num[i]);
    }
    cout << res;
    return 0;
}
