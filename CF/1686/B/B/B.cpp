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
    //对于remove某一个数字来说 会减少多少个逆序对？
    //就是单纯求逆序对
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
        vector<int> arr(n);
        rep(j, 0, n - 1) cin >> arr[j];
        int res = 0;
        for (int j = 1; j < n; j++) {
            if (arr[j - 1] > arr[j]) {
                res++;
                j++;
            }
        }
        cout << res << "\n";
    }
}
