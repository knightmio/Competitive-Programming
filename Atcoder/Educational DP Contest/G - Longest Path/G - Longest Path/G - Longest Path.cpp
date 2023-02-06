#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

#include <iostream>

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n+1);
	vector<int> degrees(n+1);
	int a, b;
	rep(i, 1, m) {
		cin >> a >> b;
		edges[a].push_back(b);
		degrees[b]++;
	}
	queue<int> q;
	rep(i, 1, n) {
		if (degrees[i] == 0) q.push(i);
	}

	vector<int> len(n+1,1);
	int res = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		res = max(res, len[temp]);
		for (auto& i : edges[temp]) {
			len[i] = max(len[temp] + 1, len[i]);
			degrees[i]--;
			if (degrees[i] == 0) q.push(i);
		}
	}
	cout << res-1;
	return 0;
}
