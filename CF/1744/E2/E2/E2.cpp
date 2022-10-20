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

//10^9以内的数最多有1344个因子
int main()
{
    int t;
    cin >> t;
    rep(i, 0, t - 1) { 
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //拆a和b的因子？
        vector<int> a1, b1;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                a1.push_back(i);
                a1.push_back(a/i);
            }
        }
        for (int i = 1; i * i <= b; i++) {
            if (b % i == 0) {
                b1.push_back(i);
                b1.push_back(b / i);
            }
        }
        bool temp = false;
        for (auto& aa : a1) {
            for (auto& bb : b1) {
                ll k = 1ll * aa * bb;
                ll x = (1ll * a / k + 1) * k;
                if (x > c) continue;
                k = 1ll * a * b / k;
                ll y = (1ll * b / k + 1) * k;
                if (y > d) continue;
                cout << x << " " << y << "\n";
                temp = true;
                break;
            }
            if (temp) break;
        }
        if(!temp) cout <<"-1 -1"<< "\n";
    }
}
