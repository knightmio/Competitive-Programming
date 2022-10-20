#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
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
    vector<int> a(n);
    //前缀和有任何意义吗？
    ll sum = 0;
    rep(i, 1, n) {
        cin >> a[i - 1];
        sum += a[i - 1];
    }
    if (sum % 2 == 1) {
        cout << "NO";
        return 0;
    }
    ll cur = 0;
    unordered_set<ll> s;

    rep(i, 1, n) {
        cur += a[i - 1];
        if (cur == sum / 2) {
            cout << "YES";
            return 0;
        }
        s.insert(a[i - 1]);
        if (s.count(cur - sum / 2)) {
            cout << "YES";
            return 0;
        }
    }
    s.clear(); s.insert(0); cur = 0;
    for (ll i = n - 1; i >= 0; i--) {
        cur += a[i];
        if (s.count(cur - sum / 2)) {
            cout << "YES" << endl;
            return 0;
        }
        s.insert(a[i]);
    }

    cout << "NO";
    return 0;
}
