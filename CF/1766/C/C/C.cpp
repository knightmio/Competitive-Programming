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
        string s1, s2;
        cin >> n >> s1 >> s2;
        int tot = 0;
        rep(j, 0, n - 1) {
            if (s1[j] == 'B') tot++;
            if (s2[j] == 'B') tot++;
        }
        //cout << tot << "\n";
        queue<pair<int,int>> q;
        q.push({ 0,0 });
        q.push({ 1,0 });
        rep(j, 0, n - 1) {
            string temp = "";
            temp += s1[j];
            temp += s2[j];
            //cout << j << " " << temp << " " << q.size() << "\n";
            if (!q.empty()) {
                int len = q.size();
                while (len--) {
                    auto a = q.front();
                    q.pop();
                    if (temp[a.first] == 'B') {
                        if(temp[(a.first - 1)* (a.first - 1)] == 'B'){
                            q.push({ (a.first - 1) * (a.first - 1) , a.second + 2 });
                            if (a.second+2 == tot) {
                                cout << "YES\n";
                                j = n;
                                break;
                            }
                        }
                        else {
                            q.push({ a.first, a.second + 1 });
                            if (a.second+1 == tot) {
                                cout << "YES\n";
                                j = n;
                                break;
                            }
                        }
                    }
                }
            }
            if (j == n - 1) cout << "NO\n";
        }
    }
}
