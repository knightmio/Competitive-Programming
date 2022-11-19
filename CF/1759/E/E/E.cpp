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
    vector<vector<int>> comb = { {2,2,3},{2,3,2},{3,2,2} };
    rep(i, 0, t - 1) { 
        ll n, h;
        cin >> n >> h;
        vector <ll> astro(n);
        rep(j, 0, n - 1) {
            cin >> astro[j];
        }
        sort(all(astro));
        int res = 0;
        int temp = h;
        rep(j, 0, 2) {
            h = temp;
            int idx = 0;
            int count = 0;
            while (idx < n && h > astro[idx]) {
                h += astro[idx] / 2;
                idx++;
                count++;
            }
            h *= comb[j][0];
            while (idx < n && h > astro[idx]) {
                h += astro[idx] / 2;
                idx++;
                count++;
            }

            h *= comb[j][1];
            while (idx < n && h > astro[idx]) {
                h += astro[idx] / 2;
                idx++;
                count++;
            }
            h *= comb[j][2];
            while (idx < n && h > astro[idx]) {
                h += astro[idx] / 2;
                idx++;
                count++;
            }
            //cout << h << " " << count << "\n";
            res = max(res, count);
        }
        cout <<res << "\n";
    }
}
