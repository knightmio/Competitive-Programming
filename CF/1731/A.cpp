// Problem: A. Joey Takes Money
// Contest: Codeforces - Codeforces Round #841 (Div. 2) and Divide by Zero 2022
// URL: https://codeforces.com/contest/1731/problem/0
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
    	rep(k,0,n-1){
    		long long temp;
    		cin >> temp;
    		res *= temp;
    	}
    	res += n-1;
    	cout << res * 2022 << "\n";
   }
}