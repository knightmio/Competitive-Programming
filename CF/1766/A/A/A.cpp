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
        if (n < 10) {
            cout << n << "\n";
        }
        else {
            int res = 0;
            int temp = 1;
            while (temp <= n) temp *= 10;
            temp /= 10;
            res += n / temp;
            temp /= 10;
            while (temp > 0) {
                res += 9;
                temp /= 10;
            }
            cout << res << "\n";
        }
    }
}
