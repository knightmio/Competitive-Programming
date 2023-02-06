// Problem: B. Kill Demodogs
// Contest: Codeforces - Codeforces Round #841 (Div. 2) and Divide by Zero 2022
// URL: https://codeforces.com/contest/1731/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
    	long long res = 1;
    	res = 1ll*n*(n+1);
    	int div = 6;
    	if(res % 2 == 0){
    		res /= 2;
    		div /= 2;
    	}
    	if(res % 3 == 0){
    		res /= 3;
    		div /= 3;
    	}
    	res %= 1000000007;
    	res *= 1ll*((4ll*n-1)/div);
    	res %= 1000000007;
    	res *= 2022;
    	res %= 1000000007;
    	cout << res << "\n";
   }
}