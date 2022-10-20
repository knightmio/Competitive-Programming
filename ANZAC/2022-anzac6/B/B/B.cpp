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
    unordered_map<string, int> mp;
    unordered_map<int, string> mp2;

    string temp;
    rep(i, 0, n - 1) {
        cin >> temp;
        mp[temp] = i;
        mp2[i] = temp;
    }
    int count;
    cin >> count;
    string a, b;
    vector<int> score(n);
    rep(i, 0, count - 1) {
        cin >> a >> b;
        if (b == "F") score[mp[a]] += 20;
        if (b == "T") score[mp[a]] += 25;
        if (b == "W") score[mp[a]] += 15;
        if (b == "H") score[mp[a]] += 30;
        if (b == "L") score[mp[a]] += 25;
        if (b == "S") score[mp[a]] += 20;
    }
    priority_queue<pair<int, int>> pq;
    rep(i, 0, n - 1) {
        pq.push({ score[i], i });
    }

    cout << "Star of the week is " << mp2[pq.top().second] << ".\n";
    pq.pop();
    cout << "Music CD for " << mp2[pq.top().second] << ".\n";
    pq.pop();
    cout << "Karakia leader is " << mp2[pq.top().second] << ".\n";
    return 0;
}
