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
        string s;
        cin >> s;
        int a = 0;
        int b = 0;
        rep(j, 0, n - 1) {
            if (s[j] == '0') {
                a++;
            }
            else {
                b++;
            }
        }
        int count = 0;
        int idx = 0;
        while (idx < n && s[idx] == '0') {
            a--;
            idx++;
        }
        while (a != 0) {
            swap(a, b);
            count++;
            if (count % 2 == 1) {
                while (idx < n && s[idx] == '1') {
                    a--;
                    idx++;
                }
            }else{
                while (idx < n && s[idx] == '0') {
                    a--;
                    idx++;
                }
            }
        }
        cout << count << "\n";
    }
}
