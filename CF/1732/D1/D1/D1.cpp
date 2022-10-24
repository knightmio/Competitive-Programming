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
    int q;
    cin >> q;
    unordered_set<ll> s;
    s.insert(0);
    unordered_map<ll, int> mp;
    rep(i, 0, q - 1) {
        string a, b;
        cin >> a >> b;
        if (a == "+") {
            s.insert(stoll(b));
        }else{
            ll mult = 1;
            ll bb = stoll(b);
            if (bb < 1e9) {
                for (ll j = 2; j * j <= bb; j++) {
                    if (bb % j == 0) {
                        if (mp.count(j)) {
                            mult = max(mult, mp[j] / (bb / j));
                        }
                        if (mp.count(bb / j)) {
                            mult = max(mult, mp[j] / j);
                        }
                    }
                }
            }
            
            while (s.count(bb * mult)) mult++;
            mp[bb] = mult;
            cout << bb * mult << "\n";
        }
    }
}
