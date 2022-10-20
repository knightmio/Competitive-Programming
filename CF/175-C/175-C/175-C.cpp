#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
int main() {
    long long n;
    long long m;
    cin >> m;
    vector<pair<long long, long long>> mons;
    long long a, b;
    rep(i, 0, m - 1) {
        cin >> a >> b; 
        mons.push_back({ a,b });
    }
    cin >> n;
    vector<long long> p;
    rep(i, 0, n - 1) {
        cin >> a; 
        p.push_back(a);
    }
    sort(mons.begin(), mons.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });
    
    long long res = 0;
    int index = 0;
    long long pre = 0;
    rep(i, 0, n - 1) {
        long long temp = p[i] - pre;
        //cout << index << " ";
        while (temp > 0) {
            if (index == m) {
                cout << res;
                return 0;
            }
            if (mons[index].first <= temp) {
                temp -= mons[index].first;
                res += 1ll * mons[index].first * mons[index].second * (i + 1);
                index++;
            }else{
                mons[index].first -= temp;
                res += 1ll * temp * mons[index].second * (i + 1);
                temp = 0;
            }
        }
        if (index == m) {
            cout << res;
            return 0;
        }
        pre = p[i];
    }
    while (index != m) {
        res += 1ll * mons[index].first * mons[index].second * (n + 1);
        index++;
    }
    cout << res;
    return 0;
}