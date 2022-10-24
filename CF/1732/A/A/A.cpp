#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
#include <numeric>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
        vector<int> v(n);
        int temp = 0;

        rep(j, 0, n - 1) {
            cin >> v[j];
            temp = gcd(temp, v[j]);
        }
        int res = 3;
        if (temp == 1) {
            res = 0;
        }
        else if (n == 1) {
            res = 1;
        }
        else {
            temp = 0;
            rep(j, 0, n - 3) temp = gcd(temp, v[j]);
            if (gcd(gcd(temp, v[n - 1]), gcd(v[n - 2], n-1)) == 1) res = 2;
            if (gcd(gcd(temp, v[n - 2]), gcd(v[n - 1], n)) == 1) res = 1;

        }

        cout << res << "\n";
    }
}