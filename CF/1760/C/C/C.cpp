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
        vector<int> idx(n);
        iota(all(idx), 0);
        vector<int> arr(n);
        rep(j, 0, n - 1) {
            cin >> arr[j];
        }
        sort(all(idx), [&](const auto& a, const auto& b) {
            return arr[a] < arr[b];
        });
        //for (auto& a : idx) cout << a << " ";
        rep(j, 0, n - 1) {
            if (j == idx[idx.size() - 1]) {
                cout << arr[j] - arr[idx[idx.size() - 2]] << " ";
            }
            else {
                cout << arr[j] - arr[idx[idx.size() - 1]] << " ";
            }
        }
        cout << "\n";
    }
}
