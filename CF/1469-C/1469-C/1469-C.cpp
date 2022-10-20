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
	int t,n,k;
	int l, r;
	cin >> t;
	int arr[200005];
	rep(i, 0, t - 1) {
		cin >> n >> k;
		rep(j, 0, n - 1) cin >> arr[j];
		int f = 1;
		l = r = arr[0];
		rep(j, 1, n - 1) {
			l = max(l - k + 1, arr[j]);
			r = min(r + k - 1, arr[j] + k - 1);
			if (l > r) {
				f = 0;
				break;
			}
		}
		if (f && l == arr[n - 1]) {
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}

	return 0;
}
