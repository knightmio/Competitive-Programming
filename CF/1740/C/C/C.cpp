#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()


int main()
{
    //w1 > w2 > w3的情况 - 值为w1 - w3
    //w1 > w3 > w2的情况 - 值为w1 + w3 - 2 * w2
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
        vector<int> input(n);
        rep(j, 0, n - 1) cin >> input[j];
        sort(input.begin(), input.end());
        ll res = 0;
        for (int j = n - 1; j >= 2; j--) {
            res = max(res, 2ll * input[j] - input[0] - input[j - 1]);
        }
        for (int j = 0; j < n-2; j++) {
            res = max(res, -2ll * input[j] + input[n - 1] + input[j + 1]);
        }
        cout << res << "\n";
    }
}

