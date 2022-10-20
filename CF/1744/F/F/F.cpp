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
        int len;
        cin >> len;
        vector<int> v(len);
        rep(j, 0, len - 1){
            int val;
            cin >> val;
            v[val] = j;
        }
        ll res = 0;
        int l = v[0];
        int r = v[0];
        rep(j, 0, len - 1) {
            int next = v[j];
            if (next > r) {
                r = next;
            }
            if (next < l) {
                l = next;
            }
            if (r - l + 1 <= (j + 1) * 2 -1) {
                int space = (j + 1) * 2 - 1 - (r - l + 1);
                //cout << "len " << (j + 1) * 2 - 1;
                //cout << " space " << space;
                if (len - 1 - r + l >= space) {
                    //左边最多选l个
                    //最少选space - （len - 1 - r） 个
                    int left = min(space, l) - max((space - (len - 1 - r)),0) + 1;
                    int right = min(space, (len - 1 - r)) - max(0,(space - l)) + 1;
                    res += min(left,right);
                }
                //cout << " res " << res << "\n";
            }
            if (r - l + 1 <= (j + 1) * 2) {
                int space = (j + 1) * 2 - (r - l + 1);
                //cout << "len " << (j + 1) * 2 - 1;
                //cout << " space " << space;
                if (len - 1 - r + l >= space) {
                    //左边最多选l个
                    //最少选space - （len - 1 - r） 个
                    int left = min(space, l) - max((space - (len - 1 - r)), 0) + 1;
                    int right = min(space, (len - 1 - r)) - max(0, (space - l)) + 1;
                    res += min(left, right);
                }
                //cout << " res " << res << "\n";
            }
        }
        cout << res << "\n";
    }
    return 0;
}