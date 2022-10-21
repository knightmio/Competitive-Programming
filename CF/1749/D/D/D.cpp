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
    int n;
    ll m;
    cin >> n >> m;
    vector<bool> prime(n + 1, true);
    rep(i, 2, n) {
        if (prime[i]) {
            rep(j, 2, n) {
                if (i * j > n)break;
                prime[i * j] = false;
            }
        }
    }
    ll res = 0;
    //遍历所有不存在的可能 从一位（一位的时候所有都不成立 所以要计算）到n位？
    ll mult = 1;
    ll pre = 1;
    rep(i, 1, n) {
        //是素数 筛扩大
        if (prime[i]) mult *= i;
        if (mult > m) break;
        pre *= (m / mult % 998244353);
        pre %= 998244353;
        res += pre;
        res %= 998244353;
    }

    ll sum = 0;
    ll pow = 1;
    rep(i, 0, n - 1) {
        pow *= (m % 998244353);
        pow %= 998244353;
        //cout << pow << " ";
        sum = (sum + pow) % 998244353;
    }
    cout << (sum - res + 998244353) % 998244353;
}

