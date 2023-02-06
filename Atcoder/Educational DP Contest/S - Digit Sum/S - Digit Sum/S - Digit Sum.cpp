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
	string k;
	int d;
	cin >> k >> d;
	int n = k.size();
	vector<vector<ll>> dp(k.size() + 1, vector<ll>(d+1,-1));
	//第一个int表示第几位
	//第二个int表示需要什么值
	//第三个bool表示是否受限
	function<int(int, int, bool)> f = [&](int i, int need, bool is_limit) -> int {
		//cout << i << " " << n << " "<< need << " "<< is_limit <<"\n";
		if (!is_limit && dp[i][need] != -1) return dp[i][need];
		if (i == n) {
			int cnt = 0;
			for (int cur = 0, up = is_limit ? (k[i - 1] - '0') : 9; cur <= up; ++cur) {
				//cout << cur << "\n";
				if ((need - cur + d) % d == 0)cnt++;
			}
			return cnt;
		}

		ll res = 0;
		for (int cur = 0, up = is_limit ? (k[i - 1] - '0') : 9; cur <= up; ++cur) {
			res += f(i + 1, ((need - cur) % d + d) %d, is_limit && cur == up);
			res %= 1000000007;
			//cout << i << " " << need << " " << cur << " " << res << "\n";
		}
		if (!is_limit) dp[i][need] = res;
		return res;
	};
	
	cout << (f(1, d, true)-1+ 1000000007)% 1000000007;
	return 0;
}
