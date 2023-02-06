#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
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
    int n;
    cin >> n;
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) != 1) {
            cout << "0\n";
        }
        else if (abs(a - b) == 1) {
            cout << "-1\n";
        }
        else {
            int diff = abs(a - b);
            int res = INT_MAX;
            for (int j = 1; j * j <= diff; j++) {
                if (diff % j == 0) {
                    res = 0;
                    break;
                }
                if (diff % j == 0) {
                    if(j != 1)res = min(res, (j - a % j) % j);
                    res = min(res, (diff/j - a % (diff / j)) % (diff / j));
                }
            }
            cout << res << "\n";
        }
    }
}
