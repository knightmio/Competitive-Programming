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
        int m, s;
        cin >> m >> s;
        int sum = 0;
        int ma = 0;
        rep(j, 0, m-1) {
            int a;
            cin >> a;
            sum += a;
            ma = max(a, ma);
        }
        int diff = (1 + ma) * ma / 2 - sum;
        if (s < diff) {
            cout << "NO\n";
        }
        else {
            s -= diff;
            while (s >= 0){
                if (s == 0) {
                    cout << "YES\n";
                    break;
                }
                s -= (ma + 1);
                ma++;
                if (s < 0) {
                    cout << "NO\n";
                    break;
                }
            }
        }
    }
}
