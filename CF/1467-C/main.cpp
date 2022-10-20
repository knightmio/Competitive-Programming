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
    //一眼贪心 但是该怎么减少？ 在最后一步的时候我们存在两个数组a, b且各有一个值
    //求两个最小值x, y？ sum - 2x - 2y?
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    ll temp;
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    //这里的储存也没有意义
    rep(i, 1, n1)cin>>temp, sum1 += temp, min1 = min(min1,temp);
	rep(i, 1, n2)cin>>temp, sum2 += temp, min2 = min(min2,temp);
	rep(i, 1, n3)cin>>temp, sum3 += temp, min3 = min(min3,temp);
	//这个sort完全没必要啊
	//sort(all(a1)), sort(all(a2)), sort(all(a3));
	int m = min(min1 + min2, min(min3 + min2, min1 + min3));
	ll n = max(sum1 + sum2 - sum3, max(sum3 + sum2 - sum1, sum1 + sum3 - sum2));
	ll res = max(sum1 + sum2 + sum3 - 2ll*m, n);
	cout << res <<endl;
    //system("pause");
    return 0;
}
