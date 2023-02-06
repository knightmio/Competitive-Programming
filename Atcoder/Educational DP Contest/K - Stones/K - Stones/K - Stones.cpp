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
	int n, k;
	cin >> n >> k;
	set<int> s;
	rep(i, 0, n - 1) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	vector<bool> dp(k + 1, false);
	rep(i, 1, k) {
		if (s.count(i)) {
			dp[i] = true;
		}
		else {
			for (auto& a : s) {
				if (a > i) break;
				if (!dp[i - a]) {
					dp[i] = true;
					break;
				}
			}
		}
	}

	if (dp[k]) {
		cout << "First";
	}
	else {
		cout << "Second";
	}

}
