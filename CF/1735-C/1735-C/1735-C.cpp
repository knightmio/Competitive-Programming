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
    rep(i, 0, n - 1) {
        int m;
        cin >> m;
        string s;
        cin >> s;
        vector<int> to(26,-1);
        vector<int> from(26,-1);
        int count = 0;
        string temp = "";
        for (char c : s) {
            int cur = (c - 'a');
            if (to[cur] == -1) {
                rep(j, 0, 25) {
                    if (cur != j && from[j] == -1) {
                        if (count == 25 || !(from[cur] != -1 && to[j] != -1)) {
                            to[cur] = j;
                            from[j] = cur;
                            count++;
                            break;
                        }
                    }
                }
            }
            temp += ('a' + to[cur]);
        }
        cout << temp << "\n";
    }
    return 0;
}
