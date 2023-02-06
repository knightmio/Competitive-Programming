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
        string s;
        int n;
        cin >> n >> s;
        rep(j, 0, n - 2) {
            string temp = s.substr(j, 2);
            size_t found = s.find(temp);
            found = s.find(temp, found + 2);
            if (found != string::npos) {
                cout << "YES\n";
                break;
            }
            if(j == n-2)cout << "NO\n";
        }
        if(n == 1) cout << "NO\n";
    }
}