#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
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
    //暴力combination
    int n, m;
    cin >> n >> m;
    int res = INT_MAX;
    vector<unordered_set<int>> collection(n);
    rep(i, 0, n - 1) {
        int a;
        cin >> a;
        rep(j, 0, a-1) {
            int b;
            cin >> b;
            collection[i].insert(b);
        }
    }
    rep(i, 0, (1 << n) - 1) {
        unordered_set<int> s;
        int len = __popcnt(i);
        rep(j, 0, n - 1) {
            if(i & (1 << j)){
                s.insert(collection[j].begin(), collection[j].end());
            }
        }
        if (s.size() == m) {
            res = min(res, len);
        }
    }
    if (res == INT_MAX) res = -1;
    cout << res;
    return 0;
}
