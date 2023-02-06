// Problem: C. Elemental Decompress
// Contest: Codeforces - Codeforces Round #842 (Div. 2)
// URL: https://codeforces.com/contest/1768/problem/C
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
        int n;
        cin >> n;
        vector<int> res1(n,-1);
        vector<int> res2(n,-1);
        vector<int> ava1(n,1);
        vector<int> ava2(n,1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
		bool b = true;
    	rep(j,0,n-1){
    		int temp;
    		cin >> temp;
    		if(ava1[temp-1] == 0){
    			if(ava2[temp-1] == 0){
    				b = false;
    			}else{
    				ava2[temp-1] = 0;
    				res2[j] = temp;
    				pq.push({temp,2,j});
    			}
    		}else{
				ava1[temp-1] = 0;
				res1[j] = temp;
				pq.push({temp,1,j});
			}
    	}
    	if(!b){
    		cout << "NO\n";
    	}else{
    		int c1 = 0;
    		int c2 = 0;
    		while(!pq.empty()){
    			// cout << pq.top().first << " " << pq.top().second << "\n";
    			// pq.pop();
    			auto a = pq.top();
    			pq.pop();
    			if(a[1] == 1){
    				while(ava2[c2] == 0) c2++;
    				if(c2+1 > a[0]){
    					b = false;
    					break;
    				}else{
    					res2[a[2]] = c2+1;
    					ava2[c2] = 0;
    				}
    			}else{
    				while(ava1[c1] == 0) c1++;
    				if(c1+1 > a[0]){
    					b = false;
    					break;
    				}else{
    					res1[a[2]] = c1+1;
    					ava1[c1] = 0;
    				}
    			}
    		}
    		if(!b){
	    		cout << "NO\n";
	    	}else{
	    		cout << "YES\n";
	    		for(auto& a : res1) cout << a << " ";
	    		cout << "\n";
	    		for(auto& a : res2) cout << a << " ";
	    		cout << "\n";
	    	}
    	}
    	
   }
}