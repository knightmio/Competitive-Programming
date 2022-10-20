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
    //简单二维dp求最大值
    int r, c, k;
    cin >> r >> c >> k;
    ll dp[50][50] = { 0 };
    vector<vector<int>> matrix(r, vector<int>(c));

    for (int i = r - 1; i >= 0; i--) {
        rep(j, 0, c - 1) {
            cin >> matrix[i][j];
        }
    }
    ll sum[50][50] = { 0 };
    rep(i, 0, r - 1) {
        ll temp = 0;
        rep(j, 0, k-1) {
            temp += matrix[i][j];
        }
        sum[i][0] = temp;
        rep(j, 1, c - k) {
            temp = temp - matrix[i][j - 1] + matrix[i][j + k - 1];
            sum[i][j] = temp;
        }
    }
    rep(i, 0, c - k) {
        dp[0][i] = sum[0][i];
        //cout << dp[0][i] << "\n";
    }
    rep(i, 1, r - 1) {
        rep(j, 0, c - k) {
            rep(z, max(0, j-k+1), min(c-k,j+k-1)){
                dp[i][j] = max(dp[i][j], sum[i][j] + dp[i - 1][z]);
            }
        }
    }
    ll res = 0;
    int idx = -1;
    rep(i, 0, c - k) {
        //cout << dp[r - 1][i] << "\n";
        if (dp[r - 1][i] > res) {
            res = dp[r - 1][i];
            idx = i;
        }
    }
    rep(i, 0, idx - 1) cout << '.';
    rep(i, 0, k-1) cout << 'X';
    rep(i,idx+k, c-1)cout << '.';
    cout << "\n";
    for (int i = r - 2; i >= 0; i--) {
        res = 0;
        int temp = -1;
        rep(z, max(0, idx - k + 1), min(c - k, idx + k - 1)) {
            if (dp[i][z] > res) {
                res = dp[i][z];
                temp = z;
            }
        }
        idx = temp;
        rep(i, 0, idx - 1) cout << '.';
        rep(i, 0, k - 1) cout << 'X';
        rep(i, idx + k, c - 1)cout << '.';
        cout << "\n";
    }
    /*rep(i, 0, r - 1) {
        rep(j, 0, c-k) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    //cout << dp[0][0];
    return 0;
}