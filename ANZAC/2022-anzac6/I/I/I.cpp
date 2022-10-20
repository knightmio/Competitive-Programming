#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    int n;
    cin >> n;
    vector<int> list(n);
    rep(i, 0, n - 1) cin >> list[i];
    sort(list.begin(), list.end());
    vector<int> pre(n);
    vector<int> suf(n);

    //0到k的最短路径
    rep(i, 0, n - 1) {
        int temp = INT_MAX;
        rep(j, 0, i) {
            int count = 0;
            rep(k, 0, i) {
                count += abs(list[k] - list[j]);
            }
            if (count <= temp) {
                temp = count;
            }
            else {
                break;
            }
        }
        pre[i] = temp;
        temp = INT_MAX;
        rep(j, i+1, n-1) {
            int count = 0;
            rep(k, i+1, n-1) {
                count += abs(list[k] - list[j]);
            }
            if (count <= temp) {
                temp = count;
            }
            else {
                break;
            }
        }
        suf[i] = temp;
    }
    int res = INT_MAX;
    rep(i, 0, n - 1) {
        res = min(res, 2 * (pre[i] + suf[i]));
    }
    cout << res;
    return 0;
}
