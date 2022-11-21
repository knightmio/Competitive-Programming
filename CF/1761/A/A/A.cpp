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
	int t;
	cin >> t;
	rep(i, 0, t - 1) {
		int n,a,b;
		cin >> n >> a >> b;
		if (a == b && a == n) {
			cout << "Yes\n";
		}
		else if (a + b < n-1) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}
