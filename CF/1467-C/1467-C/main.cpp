#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    ll temp;
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    rep(i, 1, n1)cin >> temp, sum1 += temp, min1 = min(min1, temp);
    rep(i, 1, n2)cin >> temp, sum2 += temp, min2 = min(min2, temp);
    rep(i, 1, n3)cin >> temp, sum3 += temp, min3 = min(min3, temp);
    ll ans = sum1 + sum2 + sum3;
    ll m = min(min1 + min2, min(min3 + min2, min1 + min3));
    m = min({ m, sum1, sum2, sum3 });
    cout << (ans - m * 2) << endl;
    
    //system("pause");
    return 0;
}