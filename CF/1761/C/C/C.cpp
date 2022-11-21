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
		int n;
		cin >> n;
		map<int, vector<int>> mp;
		map<int, vector<int>> mp2;

		rep(j, 0,n - 1) {
			string s;
			cin >> s;
			rep(k, 0, s.size() - 1) {
				if (s[k] == '1') {
					mp[k].push_back(j);
					mp2[j].push_back(k);

				}
			}
		}
		vector<int> indegrees(n);
		vector<set<int>> res(n);
		queue<int> q;
		rep(j, 0, n - 1){
			indegrees[j] = mp[j].size();
			if (indegrees[j] == 0) q.push(j);
		}
		int count = 1;
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			set<int> cur;
			for (auto& a : mp[temp]) {
				cur.insert(res[a].begin(), res[a].end());
			}
			cur.insert(count);
			count++;
			res[temp] = cur;
			for (auto& a : mp2[temp]) {
				indegrees[a]--;
				if (indegrees[a] == 0) q.push(a);
			}
		}
		for (auto& a : res) {
			cout << a.size() << " ";
			for (auto& b : a) cout << b << " ";
			cout << "\n";
		}
	}
}
