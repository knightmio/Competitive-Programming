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
    string s;
    cin >> s;
    int idx = 0;
    while (idx < n && s[idx] == '0') idx++;
    if (idx == n) {
        cout << "0";
        return 0;
    }
    s = s.substr(idx);
    //暴力匹配？
    string res = s;
    string temp = s;
    rep(i, 0, min(20,n-1)) { 
        temp.pop_back();
        string ans = s;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[temp.size() - 1 - i] == '1') {
                ans[ans.size() - 1 - i] = '1';
            }
        }
        res = max(res, ans);
    }
    cout << res;
    return 0;
}