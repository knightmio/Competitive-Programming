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
ll dp[100000][2][4] = { 0 };
int main()
{
	//对于任何一个已经成立的n长回文数 有多少种去除方式？
	//不去除 1种
	//去除一个
	//当成三维dp来做
	//dp[i][j][k] i表示当前是第几个字符 j表示当前的串以0或者1结尾 k表示当前选取的字符长度？
	//i的范围是1e5 最多是8e5的范围 能开
	string in;
	cin >> in;
	int n = in.size();
	ll res = 0;
	if (in[0] == '1') {
		//如果第一位是1 可以选也可以不选
		//不选 当前串长度为0
		dp[0][0][0] = 1;
		//选 当前串长度为1
		dp[0][1][1] = 1;
	}
	if (in[0] == '0') {
		//如果第一位是0 不可以选
		//不选 当前串长度为0
		dp[0][0][0] = 1;
	}
	//选第几个数字
	rep(i, 1, n - 1) {
		//不选的操作都是一样的 继承f-1
		rep(j, 0, 1) {
			rep(k, 0, 3) {
				dp[i][j][k] = dp[i - 1][j][k];
			}
		}
		//找上一个是0的
		if (in[i] == '1') {
			//选
			rep(j, 1, 3) {
				dp[i][1][j] += dp[i - 1][0][j - 1];
				dp[i][1][j] %= 1000000007;
			}
			dp[i][1][3] += dp[i - 1][0][3];
			dp[i][1][3] %= 1000000007;
		}
		//找上一个是1的
		if (in[i] == '0') {
			//选
			rep(j, 1, 3) {
				dp[i][0][j] += dp[i - 1][1][j - 1];
				dp[i][0][j] %= 1000000007;
			}
			dp[i][0][3] += dp[i - 1][1][3];
			dp[i][0][3] %= 1000000007;
		}
		/*res += dp[i][1][3];
		res %= 1000000007;*/
	}
	cout << dp[n-1][1][3] << "\n";
	//cout << dp[n - 1][0][3] << "\n";

	return 0;
}
