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
        int n, m;
        cin >> n >> m;
        rep(j, 0, m-1) { 
            int x, y;
            cin >> x >> y;
        }
        if (n <= m){
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}
