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
    vector<int> arr(n);
    rep(i, 0, n - 1) cin >> arr[i];
    //左右单调栈？单调递减栈
    stack<int> s;
    int res;
    rep(i, 0, n - 1) {
        while (!s.empty()){
            res = max(res, arr[s.top()] ^ arr[i]);
            if (arr[s.top()] < arr[i]) {
                s.pop();
            }else{
                break;
            }
        }
        s.push(i);
    }
    cout << res;
    return 0;
}
