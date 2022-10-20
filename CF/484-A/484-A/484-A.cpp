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
    int t;
    cin >> t;
    long long a, b;
    rep(i, 0, t - 1) {
        cin >> a >> b;
        while ((a | (a + 1)) <= b) a |= a + 1;
        cout << a << "\n";
    }
    return 0;
}
