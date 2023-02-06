// Problem: C. Even Subarrays
// Contest: Codeforces - Codeforces Round #841 (Div. 2) and Divide by Zero 2022
// URL: https://codeforces.com/contest/1731/problem/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

ll mp[1000007];
int main()
{
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n;
        cin >> n;
    	vector<int> s;
    	int len = 0;
    	while((1<<len) <= n) len++;
    	for(int j = 0; j*j <= (1<<len); j++) s.push_back(j*j);
   		//cout << (1<<len) << "\n";
    	long long res = 0;
    	vector<int> v(n);
    	rep(j,0,n-1){
    		 cin >> v[j];
    		 //if(s.count(v[j])) res++;
    	}
    	//cout<< res <<"?\n"; 
    	for(int i=0;i<=(1<<len);i++)mp[i]=0;
    	mp[0]=1;
    	int temp = 0;
    	rep(j,0,n-1){
    		temp ^= v[j];
    		for(auto& num : s){
    			//cout << "cur : " << temp << " find " << num << " add "<<mp[(temp ^ num)] << "\n";
    			res += mp[(temp ^ num)];
    		}
 //   		cout << res << "\n";
    		mp[temp]++;
    	}
    	//cout<<res <<"\n";
    	cout << 1ll*n*(n+1)/2 - res << "\n";
   }
}