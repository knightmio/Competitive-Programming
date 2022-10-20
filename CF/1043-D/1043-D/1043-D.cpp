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
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<vector<int>> pos(m, vector<int>(n + 1, -1));
    vector<long long> maxlen(n + 1, 1);

    rep(i, 0, m - 1) {
        rep(j, 0, n - 1) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
    rep(i, 1, n - 1) {
        //cout << i << "\n";
        bool temp = true;
        rep(j, 0, m - 1) {
            if (pos[j][a[0][i]] != pos[j][a[0][i - 1]] + 1) {
                temp = false;
                break;
            }
        }
        if (temp) maxlen[a[0][i]] = maxlen[a[0][i - 1]] + 1;
    }
    //cout << maxlen[3] << "\n"; 
    cout << accumulate(maxlen.begin(), maxlen.end(), 0LL) - 1;
    return 0;
}
