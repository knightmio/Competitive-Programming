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
        int n;
        cin >> n;
        if (n % 2 == 1) {
            rep(j, 0, n - 1)cout << "1 ";
            cout << "\n";
        }
        else {
            cout << "1 3 ";
            rep(j, 0, n - 3)cout << "2 ";
            cout << "\n";
        }
    }
}