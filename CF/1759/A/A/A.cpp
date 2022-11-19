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
    unordered_map<char, char> mp;
    mp['Y'] = 'e';
    mp['e'] = 's';
    mp['s'] = 'Y';

    rep(i, 0, t - 1) {
        string s;
        cin >> s;
        if (s.size() == 1) {
            if (!mp.count(s[0])) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            for (int i = 0; i < s.size() - 1; i++) {
                if (!mp.count(s[i]) || mp[s[i]] != s[i + 1]) {
                    cout << "NO\n";
                    break;
                }
                if (i == s.size() - 2) cout << "YES\n";
            }
        }
    }
}
