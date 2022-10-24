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
    int q;
    cin >> q;
    map<ll, int>vis;
    map<ll, ll>last;
    map<ll, set<ll>>del;
    map<ll, vector<ll>>change;
    rep(i, 0, q - 1) {
        string a;
        ll b;
        cin >> a >> b;
        if (a == "+") {
            vis[b] = 1;
            for (auto& a : change[b]) {
                del[a].erase(b);
            }
        }
        else  if (a == "-") {
            vis[b] = 0;
            for (auto& a : change[b]) {
                del[a].insert(b);
            }
        }else {
            if (!last.count(b))last[b] = b;
            //如果del里面有 直接返回set首就行了
            if (del[b].size()) {
                cout << *del[b].begin() << "\n";
            }
            else {
                while (vis[last[b]]) {
                    change[last[b]].push_back(b);
                    last[b] += b;
                }
                cout << last[b] << endl;
            } 
        }
    }
}

