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
        int z = 0;
        int o = 0;
        int cz = 0;
        int co = 0;
        char pre = ' ';
        int count = 0;
        char c;
        rep(j, 0, n - 1) {
            cin >> c;
            if (c == pre) {
                count++;
            }
            else {
                if (pre == '1') {
                    co = max(co, count);
                }
                else if(pre == '0') {
                    cz = max(cz, count);
                }
                count = 1;
                pre = c;
            }
            if (c == '1') {
                o++;
            }
            else {
                z++;
            }
        }
        if (pre == '1') {
            co = max(co, count);
        }
        else if (pre == '0') {
            cz = max(cz, count);
        }
        cout << max({ 1ll*co * co,1ll * cz * cz,1ll * o * z }) << "\n";
    }
}
