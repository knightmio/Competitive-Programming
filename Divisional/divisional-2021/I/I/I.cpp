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
    vector<int> sq;
    vector<int> cu;
    vector<int> sqcu;
    unordered_set<int> s;
    for (int i = 1; i * i <= 1000000000; i++) {
        sq.push_back(i * i);
        s.insert(i * i);
    }
    for (int i = 1; i * i*i <= 1000000000; i++) {
        cu.push_back(i * i*i);
        if (s.count(i * i * i)) {
            sqcu.push_back(i * i * i);
        }
    }
    int l, r;
    cin >> l >> r;
    auto a = lower_bound(sq.begin(), sq.end(), l);
    auto b = upper_bound(sq.begin(), sq.end(), r);
    cout << b - a << " ";
    a = lower_bound(cu.begin(), cu.end(), l);
    b = upper_bound(cu.begin(), cu.end(), r);
    cout << b - a << " ";
    a = lower_bound(sqcu.begin(), sqcu.end(), l);
    b = upper_bound(sqcu.begin(), sqcu.end(), r);
    cout << b - a << " ";
    return 0;
}