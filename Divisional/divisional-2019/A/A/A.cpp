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
	int size[26] = { 0 };
	vector<map<int, int>> save(26);
	string str;
	while (getline(cin, str)) {
		int idx = str[0] - 'A';
		string len = "";
		for (int i = 2; i < str.size(); i++) {
			if (str[i] == '.')break;
			len += str[i];
		}
		auto a = str.find('=');
		string val = str.substr(a+1);
		size[idx] = max(size[idx], stoi(len) + 1);
		save[idx][stoi(len)] += stoi(val);
		if (save[idx][stoi(len)] == 0) save[idx].erase(stoi(len));
	}
	rep(i, 0, 25) {
		if (size[i] != 0) {
			cout << char('A' + i) << "\n";
			for (auto& a : save[i]) {
				cout << a.second << "\n";
			}
		}
	}
	return 0;
}
