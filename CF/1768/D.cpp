// Problem: D. Lucky Permutation
// Contest: Codeforces - Codeforces Round #842 (Div. 2)
// URL: https://codeforces.com/contest/1768/problem/D
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
    	vector<int> v(n);
    	rep(j,0,n-1){
    		 cin >> v[j];
    	}
    	vector<int> p1(n);
    	iota(p1.begin(), p1.end(), 1);
    	map<int,int> mp;
    	rep(j,0,n-1){
    		 mp[v[j]] = j;
    		 //cout << j << " " << p1[j] << "?\n";
    	}
    	int cnt = 0;
    	vector<int> temp = v;
    	bool b = true;
    	rep(j,0,n-1){
    		//cout << temp[j] << " " << p1[j] << "\n";
    		if(temp[j] != p1[j]){
    			cnt++;
    			int pos = mp[p1[j]];
    			//cout << pos << "\n";
    			int val = temp[j];
    			if(abs(temp[j] - temp[pos]) == 1) b = false;
    			swap(temp[j], temp[pos]);
    			mp[val] = pos;
    		}
    		//for(auto& a : temp) cout << a << " ";
    		
    	}
    	if(b){
			cnt++;
		}else{
			cnt--;
		}
    	cout << cnt << "\n";
   }
}