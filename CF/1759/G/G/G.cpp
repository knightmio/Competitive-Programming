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

bool solve() {
    int n;
    cin >> n;
    vector<int> res(n);
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    bool b = true;
    for (int i = 0; i < n / 2; i++) {
        cin >> res[i*2+1];
        if (!st.count(res[i * 2 + 1])) b = false;
        st.erase(res[i * 2 + 1]);
    }
    if (!b) return false;
    for (int i = n / 2 - 1; i >= 0; i--) {
        auto pos = st.lower_bound(res[i*2+1]);
        if (pos == st.begin()) return false;
        res[i * 2] = *prev(pos);
        st.erase(prev(pos));
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << '\n';
    return true;
}

int main() {
    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        if (!solve()) cout << -1 << '\n';
    }
    return 0;
}
