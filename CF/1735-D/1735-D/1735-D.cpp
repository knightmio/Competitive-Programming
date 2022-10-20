#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
const int N = 1000;
const int L = 20;
int a[N][L];
int main()
{
    int n, m;
    cin >> n >> m;
    unordered_set<long long> s;
    rep(i, 0, n - 1) {
        ll temp = 0;
        rep(j, 0, m - 1) {
            cin >> a[i][j];
            temp = temp * 3 + a[i][j];
        }
        s.insert(temp);
    }
    long long res = 0;
    rep(i, 0, n - 1) { 
        int cnt = 0;
        rep(j, 0, n - 1) {
            if (i != j) {
                ll temp = 0;
                rep(k, 0, m - 1) {
                    if (a[i][k] == a[j][k]) {
                        temp = temp * 3 + a[i][k];
                    }
                    else {
                        temp = temp * 3 + (3 - a[i][k] - a[j][k]);
                    }
                }
                if (s.count(temp)) cnt++;
            }
        }
        cout << i << " " << cnt << "\n";
        cnt /= 2;
        res += cnt * (cnt - 1) / 2;
    }
    cout << res;
    return  0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
