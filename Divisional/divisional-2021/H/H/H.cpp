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
char arr[50][50];

int main()
{
    int r, c, n, m;
    cin >> r >> c >> n >> m;
    //50的四次方还是很小啊 直接暴力做吗
    //预处理右下角成为终点 算前缀和
    //我觉得这个量级2秒绝对够
    rep(i, 0, r - 1) {
        rep(j, 0, c - 1) {
            cin >> arr[i][j];
        }
    }
    int res = 0;
    rep(i, 0, r - n) {
        rep(j, 0, c - m) {
            bool temp = true;
            rep(k, i, n - 1+i) {
                rep(l, j, m - 1+j) {
                    if (arr[k][l] == 'A') {
                        temp = false;
                        break;
                    }
                }
                if (!temp)break;
            }
            if (temp) res++;
        }
    }
    rep(i, 0, r - m) {
        rep(j, 0, c -n) {
            bool temp = true;
            rep(k, i, m - 1+i) {
                rep(l, j, n - 1+j) {
                    if (arr[k][l] == 'A') {
                        temp = false;
                        break;
                    }
                }
                if (!temp)break;
            }
            if (temp) res++;
        }
    }
    if (n == m) res /= 2;
    cout << res;
    return 0;
}
