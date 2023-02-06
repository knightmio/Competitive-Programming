// Problem: D. Valiant's New Map
// Contest: Codeforces - Codeforces Round #841 (Div. 2) and Divide by Zero 2022
// URL: https://codeforces.com/contest/1731/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        rep(j,0, n-1){
        	rep(k,0,m-1){
        		cin >> v[j][k];
        	}
        }
        int l = 1;
        int r = min(n,m);
        while(l <= r){
        	int mid = (l+r) >> 1;
        	vector<vector<int>> hori(n, vector<int>(m));
        	vector<vector<int>> vert(n, vector<int>(m));
			int cnt = 0;
			rep(j,0, n-1){
	        	rep(k,0,m-1){
	        		if(v[j][k] >= mid){
	        			cnt++;
	        		}else{
	        			cnt = 0;
	        		}
	        		if(cnt >= mid) hori[j][k]
	        	}
	        }
        }
   }
}