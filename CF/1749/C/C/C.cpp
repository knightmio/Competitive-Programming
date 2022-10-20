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
        int res = 0;
        vector<int> arr(n);
        rep(j, 0, n - 1) cin >> arr[j];
        sort(arr.begin(), arr.end());
        rep(j, 1, n) {
            deque<int> d;
            for (auto& a : arr) {
                if (a <= j) d.push_back(a);
            }
            rep(k, 1, j) {
                while (!d.empty() && d.back() > j - k + 1) d.pop_back();
                if (d.empty()) break;
                d.pop_back();
                if (!d.empty()) d.pop_front();
                if (k == j) res = max(res, j);
            }
        }
        cout << res << "\n";
    }
}