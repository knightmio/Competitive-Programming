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
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
        unordered_set<int> s;
        ll sum = 0;
        int a;
        rep(j, 0, n - 1) {
            cin >> a;
            s.insert(a);
            sum += a;
        }
        if (sum % n != 0 || !s.count(sum / n)) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}
