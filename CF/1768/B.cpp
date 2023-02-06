// Problem: B. Quick Sort
// Contest: Codeforces - Codeforces Round #842 (Div. 2)
// URL: https://codeforces.com/contest/1768/problem/B
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
        int n,k;
        cin >> n >> k;
    	vector<int> v(n);
    	rep(j,0,n-1){
    		 cin >> v[j];
    	}
    	vector<int> temp = v;
    	sort(temp.begin(), temp.end());
    
    	int res = 0;
    	if(temp == v){
    		 cout << res << "\n";
    	}else{
    		int cur = 1;
    		rep(j,0,n-1){
    			if(v[j] == cur){
    				cur++;
    			}else{
    				res++;
    			}
    		}
    		cout << res/k + (res % k != 0 ? 1:0) << "\n";
    	}
   }
}