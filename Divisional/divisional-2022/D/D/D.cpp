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

// 组合数模板
// 乘法逆元解决大数组合
const int MOD = 1e9 + 7;
class Comb {
	vector<int> Facs, Invs;
public:
	Comb() : Facs({ 1 }), Invs({ 1 }) {}
	int operator() (int n, int k) {
		assert(k <= n);
		for (int i = Facs.size(), a, p, ans; i <= n; ++i) {
			Facs.push_back(1ll * Facs.back() * i % MOD);
			for (a = Facs[i], p = MOD - 2, ans = 1; p; p >>= 1, a = 1ll * a * a % MOD)
				if (p & 1) ans = 1ll * ans * a % MOD;
			Invs.push_back(ans);
		}
		return (1ll * Facs[n] * Invs[n - k] % MOD) * Invs[k] % MOD;
	}
};
Comb comb; // 最好放在类的外面定义，减少重复计算
unordered_map<int, unordered_set<ll>> mp;
bool verify(int m, int r) {
	ll ans = comb(m, r);
	if (m == r) return ans == 1;
	if (r == 1) return ans == m;
	if (mp[m].count(r)) return true;
	if (ans - comb(m - 1, r) == comb(m - 1, r - 1)) {
		mp[m].insert(r);
		return true;
	}
	return false;
}
int main() {

	int n;
	cin >> n;

	long long int ans = 1;

	for (int i = 0; i < n; i++) {
		int m, r;
		cin >> m >> r;
		ll temp = comb(m, r);
		//我需要知道这个temp是否超过1e9+7
		queue<pair<int, int>> q;
		q.push({ m,r });
		rep(i, 0, 10) {
			int len = q.size();
			while (len--) {
				auto a = q.front();
				q.pop();
				if (!verify(a.first, a.second)) {
					cout << "BIG ENOUGH";
					return 0;
				}
				if (a.first > a.second)q.push({ a.first - 1, a.second });
				if (a.second > 1)q.push({ a.first - 1, a.second - 1 });
			}
		}
		ans *= temp;
		if (ans > 1e9) {
			cout << "BIG ENOUGH";
			return 0;
		}

	}

	if (ans > 1e9) {
		cout << "BIG ENOUGH";
	}
	else {
		cout << ans;
	}

	return 0;

}