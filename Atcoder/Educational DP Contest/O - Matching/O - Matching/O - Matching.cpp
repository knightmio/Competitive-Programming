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

template <typename Dtype>
unsigned int __builtin_popcount(Dtype u)
{
	u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
	u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
	u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
	u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
	u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
	return u;
}//wishchin!!! 

int main()
{
	//状压女人 滚动数组？
	int n;
	cin >> n;
	vector<vector<int>> input(n, vector<int>(n));
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			cin >> input[i][j];
		}
	}
	vector<ll> dp(1 << n);
	dp[0] = 1;
	rep(i, 1, n) {
		vector<ll> dp2(1 << n);
		for (int j = 1; j < (1 << n); j++) {
			if (__builtin_popcount(j) == i) {
				//cout << j << " " << __builtin_popcount(j) << "\n";
				for (int k = 0; k < n; k++) {
					if (input[i - 1][k] == 0)continue;
					if (j & (1 << k)) {
						dp2[j] += dp[j - (1 << k)];
						dp2[j] %= 1000000007;
					}
				}
			}
		}
		dp = dp2;
		/*for (auto& a : dp) cout << a << " ";
		cout << "\n";*/
	}
	cout << dp[(1 << n) - 1];
}
