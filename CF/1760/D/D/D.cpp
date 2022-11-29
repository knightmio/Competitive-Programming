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
    rep(in, 0, t - 1) {
        int n;
        cin >> n;
        vector<int> arr(n);
        rep(j, 0, n - 1) cin >> arr[j];
        int pre = arr[0];
        bool de = true;
        bool res = true;
        rep(j, 1, n - 1) { 
            if (arr[j] > pre) {
                de = false;
            }
            if (arr[j] < pre) {
                if (de == false) {
                    res = false;
                    break;
                }
            }
            pre = arr[j];
        }
        if (res) {
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

