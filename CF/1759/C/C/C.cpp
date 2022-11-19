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
        int l, r, x, a,b;
        cin >> l >> r >> x >> a >> b;
        if (a == b) {
            cout << "0\n";
        }
        else {
            if (abs(a - b) >= x) {
                cout << "1\n";
            }else{
                if((max(abs(a - l), abs(a - r)) < x) || (max(abs(b - l), abs(b - r)) < x)){
                   cout << "-1\n";
                }else{
                    if (a < b) {
                        if ((r >= b + x) || abs(a-l) >= x) {
                            cout << "2\n";
                        }
                        else {
                            cout << "3\n";
                        }
                    }
                    else {
                        if ((l <= b - x) || abs(a - r) >= x) {
                            cout << "2\n";
                        }
                        else {
                            cout << "3\n";
                        }
                    }
                }
            }
        }
    }
}

