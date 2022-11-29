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
        ll n, c, d;
        cin >> n >> c >> d;
        vector<int> coins(n);
        rep(j, 0, n - 1) cin >> coins[j];
        int ma = *max_element(all(coins));
        
            sort(all(coins),greater<int>());
            int l = -1;
            int r = d+1;
            while (l < r) {
                int mid = ((l + r+1) >> 1);
                long long tot = 0;
                for (int i = 0; i < d; i++) {
                    int id = i % (mid + 1);
                    if (id < n) {
                        tot += coins[id];
                    }
                }
                if (tot >= c) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            if (l == d + 1) {
                cout << "Infinity" << '\n';
            }
            else {
                if (l == -1) {
                    cout << "Impossible" << '\n';
                }
                else {
                    cout << l << '\n';
                }
            }
        
    }
}
