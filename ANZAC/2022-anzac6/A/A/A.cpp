#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
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
    int m;
    cin >> m;
    string res;
    int mi = INT_MAX;
    int a;
    string b;
    rep(i, 0, m - 1) {
        cin >> b >> a;
        if (abs(a - n) < mi) {
            mi = abs(a - n);
            res = b;
        }
        //cout << mi << " ";
    }
    cout << res;
    return 0;
}
