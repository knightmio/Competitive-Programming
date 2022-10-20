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
    int b, s;
    cin >> b >> s;
    int count = 1;
    unordered_map<int, string> mp;
    unordered_map<int, int> fre;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    rep(i, 0, b - 1) {
        int x, y;
        string z;
        cin >> x >> y >> z;
        mp[count] = z;
        fre[count] = y;
        pq.push({ x + 1.0 * count / 10000,count });
        count++;
    }
    while (s--) {
        auto a = pq.top();
        pq.pop();
        pq.push({ a.first + fre[a.second],a.second });
        cout << mp[a.second] << "\n";
    }
    return 0;
}
