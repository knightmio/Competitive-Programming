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
        int n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        rep(j, 0, n - 1) cin >> arr[j];
        ll res = 1;
        rep(j, 1, n - 1) {
            if (arr[j] > arr[j - 1]) {
                cout << "0\n";
                break;
            }
        }
    }
}
