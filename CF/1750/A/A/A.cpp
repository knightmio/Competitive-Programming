﻿#include<iostream>
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
        vector<int> arr(n);
        rep(j, 0, n - 1) cin >> arr[j];
        if (arr[0] == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
