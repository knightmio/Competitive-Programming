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
	int n;
	cin >> n;
	vector<int> first(n);
	rep(i, 0, n - 1) cin >> first[i];
	vector<int> period(n);
	rep(i, 0, n - 1) cin >> period[i];
	int berries;
	cin >> berries;
	//at least
	int l = berries / 9 + 1;
	vector<int> checked(berries);
	vector<int> start((1<<n));
	rep(i, 0, berries-1) {
		int temp = 0;
		rep(j, 0, n - 1) {
			if (first[j] > i) continue;
			if ((first[j] - i) % period[j] == 0) {
				temp += (1 << j);
			}
		}
		checked[i] = temp;
		if (i < l - 1) start[checked[i]]++;
	}
	double res = 0;
	rep(i, l - 1, berries - 1) {
		start[checked[i]]++;
		vector<double> valeach(n);
		priority_queue<pair<double, int>> pq;
		double init = 0;

		rep(j, 0, n - 1) {
			double num = i >= first[j] ? (i-first[j]) / period[j] + 1 : 0;
			if (num == 0) { 
				valeach[j] = 0;
			}
			else {
				valeach[j] = 1.0 / num * (i + 1) / n;
			}
			init += valeach[j]*num;
		}

		rep(j, 0, (1 << n) - 1) {
			double temp = 0;
			rep(k, 0, n - 1) {
				if (j & (1 << k)) {
					temp += valeach[k];
				}
			}
			pq.push({ temp,j });
		}
		int left = berries - i - 1;
		while (left > 0) { 
			auto a = pq.top();
			pq.pop();	
			if (start[a.second] * 8 >= left) {
				init += a.first * left;
				left = 0;
			}
			else {
				left -= start[a.second] * 8;
				init += a.first * start[a.second] * 8;
			}
		}
		res = max(res, init);
	}
	cout << res;
}
