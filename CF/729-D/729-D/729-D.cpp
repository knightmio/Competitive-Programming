#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<int> res;
    int count = 0;
    int fire = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            count = 0;
        }
        else {
            count++;
            if (count == b) {
                count = 0;
                fire++;
                res.push_back(i + 1);
            }
        }
    }
    cout << fire - (a - 1) << "\n";
    rep(i, 0, fire - a) cout << res[i] << " ";
    return 0;
}
