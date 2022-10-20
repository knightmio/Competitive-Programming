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
    vector<int> len = { 5,4,3,2 };
    vector<string> name = { "Battleship", "Destroyer","Cruiser","Submarine" };
    string a, b;
    unordered_map<int, string> mp;
    unordered_map<int, int> type;

    rep(i, 0, 3) {
        cin >> a >> b;
        if (a[0] == b[0]) {
            mp[i] = "Vertical";
        }
        else if (a[1] == b[1]) {
            mp[i] = "Horizontal";
        }
        else {
            mp[i] = "Diagonal";
        }
        int start = (a[0] - 'A') * 1000 + (stoi(a.substr(1)) - '0');
        int end = (b[0] - 'A') * 1000 + (stoi(b.substr(1)) - '0');
        
        int difference = (end-start) / (len[i] - 1);
        rep(j, 0, len[i] - 1) {
            //cout << start + difference * j << " " << j;
            type[start + difference * j] = i;
        }
    }
    string shoot;
    while (true) {
        cin >> shoot;
        if (shoot == "X0") return 0;
        int index = (shoot[0] - 'A') * 1000 + (stoi(shoot.substr(1)) - '0');
        if (!type.count(index)) {
            cout << "Miss\n";
        }
        else {
            cout << "Hit " << name[type[index]] << " " << mp[type[index]] << "\n";
        }
    }
    
    return 0;
}
