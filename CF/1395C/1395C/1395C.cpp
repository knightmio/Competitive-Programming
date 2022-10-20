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
    //方法一：暴力枚举
    //提示 1：枚举答案 ans。
    //提示 2：这意味着 c[i] | ans = ans。
    //提示 3：对每个 a[i]，枚举看是否存在 a[j] 使得(a[i] & b[j]) | ans = ans。
    //时间复杂度 O(nmU)，U = 512。
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, m - 1) cin >> b[i];
    int u[205][205] = { 0 };
    //最多到512对吧
    /*rep(i, 0, 512) {
        bool re = true;
        for (auto& F : a) {
            bool temp = false;
            for (auto& S : b) {
                if (((F & S) | i) == i) {
                    temp = true;
                    break;
                }
            }
            if (!temp) {
                re = false;
                break;
            }
        }
        if (re) {
            cout << i;
            break;
        }
    }*/
    //方法二：从高到低逐个考虑每个比特位
    //如果答案的某个比特位可以是 0，那么需要更新 a[i] 可以选择的 b[j] 的集合。
    //时间复杂度 O(nmlogU)，U = 512。
    int c = 0;
    for (int i = 9; i >= 0; i--) {
        bool l = 0;
        for (int j = 0; j < n; j++) {
            bool ok = 1;
            for (int k = 0; k < m && ok; k++)if (!u[j][k] && !((a[j] & b[k]) & (1 << i)))ok = 0;//判断能否找到可行的方案
            //如果ok = 1表示a[j]不存在对应的b
            l |= ok;
        }
        if (l)c += l << i;
        else for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)if ((a[j] & b[k] & (1 << i)))u[j][k] = 1;//表示这个组合会导致这位成1 所以标记不考虑
    }
    cout << c;
    return 0;
}
