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
		string a, b;
		cin >> a >> b;
		vector<string> s;
		rep(j, 1, n - 1) {
			if ((a[j] ^ b[j]) != (a[j - 1] ^ b[j - 1])) {
				cout << "NO\n";
				break;
			}
			if (j == n - 1) {
				cout << "YES\n";
				bool same = (a == b);
				for (int k = 0; k < n; k++) {
					if (a[k] == '0') {
						string temp = "";
						temp = to_string(k + 1) + " " + to_string(k + 1);
						s.push_back(temp);
						same = (!same);
					}
				}
				if (same) {
					s.push_back("1 1");
					string temp = "2 " + to_string(n);
					s.push_back(temp);
				}
				else {
					string temp = "1 " + to_string(n);
					s.push_back(temp);
				}
				cout << s.size() << "\n";
				for (auto& w : s) cout << w << "\n";
			}
		}
	}
}