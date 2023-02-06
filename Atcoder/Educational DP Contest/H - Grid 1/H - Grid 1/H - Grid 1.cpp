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
	int h, w;
	cin >> h >> w;
	vector<vector<char>> dp(h, vector<char>(w));
	rep(i, 0, h - 1) {
		rep(j, 0, w - 1) {
			cin >> dp[i][j];
		}
	}
	//啊 很经典的dp题了
	vector<vector<long long>> res(h, vector<long long>(w, 0));
	res[0][0] = 1;
	for (int i = 1; i < w; i++) {
		if(dp[0][i] == '#'){
			res[0][i] = INT_MIN;
		}
		else {
			res[0][i] = res[0][i - 1];
		}
	}

	for (int i = 1; i < h; i++) {
		if (dp[i][0] == '#') {
			res[i][0] = INT_MIN;
		}
		else {
			res[i][0] = res[i-1][0];
		}
	}
	//初始化完成
	rep(i, 1, h - 1) {
		rep(j, 1, w - 1) {
			if (dp[i][j] == '#') {
				res[i][j] == INT_MIN;
			}
			else {
				//可以选上面或者左边
				if (res[i - 1][j] > 0) res[i][j] += res[i - 1][j];
				if (res[i][j - 1] > 0) res[i][j] += res[i][j - 1];
				res[i][j] %= 1000000007;
			}
		}
	}
	cout << res[h - 1][w - 1];
	return 0;
}
