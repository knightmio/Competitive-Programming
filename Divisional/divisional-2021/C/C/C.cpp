#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    int n, c;
    cin >> n >> c;
    unordered_map<char, int> best;
    unordered_map<char, int> cur;
    rep(i, 0, n - 1) {
        string temp;
        cin >> temp;
        unordered_map<char, int> mp;
        unordered_set<char> s;
        int len = temp.size() - 1;
        len = min(c - 1, len);
        rep(j, 0, len) {
            if (s.count(temp[j])) continue;
            if (cur.count(temp[j])) {
                mp[temp[j]] = cur[temp[j]] + 1;
            }
            else {
                mp[temp[j]] = 1;
            }
            s.insert(temp[j]);
        }
        s.clear();
        for (auto& a : mp) {
            best[a.first] = max(best[a.first], a.second);
        }
        cur = mp;
    }
    int longest = 0;
    for (auto& a : best) {
        longest = max(longest, a.second);
    }
    int count = 0;
    for (auto& a : best) {
        if(longest == a.second)count++;
    }
    cout << longest << " " << count;
    return 0;
}
