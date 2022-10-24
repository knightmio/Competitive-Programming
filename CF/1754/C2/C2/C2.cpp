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
        vector<int> v(n);
        int ones = 0;
        int neg = 0;
        rep(j, 0, n - 1) {
            cin >> v[j];
            if (v[j] == 1) ones++;
            if (v[j] == -1) neg++;
        }
        if (abs(ones - neg) % 2 == 1) {
            cout << "-1\n";
        }
        else if (ones == neg) {
            cout << n << "\n";
            for (int k =  1; k <= n; k++) cout << k << " " << k << "\n";
        }
        else {
            vector<pair<int, int>> res;
            int diff = abs(ones - neg);
            //1更多 需要把1变成-1
            if (ones > neg) {
                for (int k = 1; k < n; k++) {
                    if (diff == 0) break;
                    if (v[k] == 1) {
                        res.push_back({ k,k + 1 });
                        diff -= 2;
                        k++;
                    }else{
                        res.push_back({ k,k });
                    }
                }
            }
            else {
                for (int k = 1; k < n; k++) {
                    if (diff == 0) break;
                    if (v[k] == -1) {
                        res.push_back({ k,k + 1 });
                        diff -= 2;
                        k++;
                    }
                    else {
                        res.push_back({ k,k });
                    }

                }
            }
            cout << res.size() + n - res[res.size() - 1].second  << "\n";
            for (auto& a : res) {
                cout << a.first << " " << a.second << "\n";
            }
            for (int k = res[res.size() - 1].second + 1; k <= n; k++) cout << k << " " << k << "\n";
        }
    }
}
