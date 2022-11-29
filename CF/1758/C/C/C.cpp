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
        int n, x;
        cin >> n >> x;
        if (x == 1 || n % x != 0) {
            cout << "-1\n";
        }
        else if (n == x) {
            cout << x << " ";
            rep(j, 1, n - 2) {
                cout << j+1 << " ";
            }
            cout << "1\n";
        }
        else {
            vector<int> res(n);
            res[0] = x;
            res[n - 1] = 1;
            res[x-1] = n;
            rep(j, 0, n - 1) {
                if (res[j] == 0) res[j] = j+1;
            }

            int idx = x-1;
            for (int j = x; j < n-1; j++) {
                //cout << j << " " << res[j] << "\n";
                //for (auto& a : res) cout << a << " ";
                //cout << "\n";
                //cout << j << "\n";
                if (n % (j+1) == 0 && (res[j] % (idx+1) == 0)) {
                    swap(res[idx], res[j]);
                    idx = j;
                }

            }
            for (auto& a : res) cout << a << " ";
            cout << "\n";
        }
    }
}
