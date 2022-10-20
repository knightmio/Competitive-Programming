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
    int n;
    cin >> n;
    unordered_set<string> s;
    vector<string> v(n);
    rep(i,0,n-1){
        string b;
        cin >> v[i] >> b;
        if (b == "no") s.insert(v[i]);
    }
    rep(i, 0, n - 1) {
        cout << v[i] << " ";
        if (s.count(v[i])) {
            cout << '0' << "\n";
        }
        else {
            cout << s.size() << "\n";
        }
    }
    return 0;
}