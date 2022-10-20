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
vector<long> sum;
void modify(int o, int l, int r, int i, int val) {
    if (l == r) {
        sum[o] = val;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) modify(o * 2, l, m, i, val);
    else modify(o * 2 + 1, m + 1, r, i, val);
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
}


// 返回区间 [L,R] 内的元素和
long query_sum(int o, int l, int r, int L, int R) { // L 和 R 在整个递归过程中均不变，将其大写，视作常量
    if (L <= l && r <= R) return sum[o];
    long sum = 0L;
    int m = (l + r) / 2;
    if (L <= m) sum += query_sum(o * 2, l, m, L, R);
    if (R > m) sum += query_sum(o * 2 + 1, m + 1, r, L, R);
    return sum;
}
int main()
{
    //对于每个新加的数字 加上他前面比它小的 和他后面比它大的？
    //单调栈？
    //线段树区间求和
    int n;
    cin >> n;
    vector<int> v(n);
    sum.resize(n * 4);
    rep(i, 0, n - 1) cin >> v[i];
    ll res = 0;
    //栈里存index？
    rep(i, 0, n - 1) {
        res += query_sum(1, 1, n, 1, v[i]);
        modify(1, 1, n, v[i], 1);
    }
    fill(sum.begin(), sum.end(), 0);
    for (int i = n - 1; i >= 0; i--) {
        res += query_sum(1, 1, n, v[i] + 1, n);
        modify(1, 1, n, v[i], 1);
    }
    cout << res / 2;
    return 0;
}

