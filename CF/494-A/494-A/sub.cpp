#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
int main() {
    string input;
    int len = input.length();
    cin >> input;
    int count = 0;
    int num = 0;
    int min_d = 0;
    for (auto& a : input) {
        if (a == '(') {
            count++;
        }
        else {
            count--;
        }
        if (a == '#') {
            num++;
            min_d = count;
        }
        else if (count < min_d) {
            min_d = count;
        }
        if (count < 0) {
            cout << "-1" << "\n";
            return 0;
        }
    }
    if (min_d < count) {
        cout << "-1" << "\n";
        return 0;
    }
    for (int i = 0; i < num - 1; i++) {
        cout << "1" << "\n";
    }
    cout << 1 + count << "\n";
    return 0;
}