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
#include <iostream>

int main()
{
    vector<vector<int>> cases(32768,vector<int>(15));
    for (int i = 0; i < 32768; i++) {
        int temp = i;
        for (int j = 14; j >= 0; j--) {
            cases[i][j] = temp % 2;
            temp /= 2;
        }
    }
    /*for (int i = 0; i < 10; i++) {
        for (auto& a : cases[i]) cout << a << " ";
        cout << "\n";
    }*/
    int count = 0;
    for (int i = 0; i < 32768; i++) {
        int sum = accumulate(cases[i].begin(), cases[i].end(), 0);
        int pre = count;
        bool b = true;
        for (int j = 0; j < 15; j++) {
            int l = 0;
            int r = 0;
            for (int k = 0; k < 15; k++) {
                if (k == j) continue;
                if (cases[i][k] == 1) {
                    l++;
                }
                else {
                    r++;
                }
            }
            if (l == 7) continue;
            int choice = -1;
            if (l == 8 || l == 10 || l == 12 || l == 14) {
                choice = 0;
            }
            if (r == 8 || r == 10 || r == 12 || r == 14) {
                choice = 1;
            }
            if (l == 9 || l == 11 || l == 13 || l == 15) {
                choice = 1;
            }
            if (r == 9 || r == 11 || r == 13 || r == 15) {
                choice = 0;
            }
            if (choice != cases[i][j]) {
                b = false;
                if (i == 31) cout << j << " " << l << " " << r << "\n";
                break;
            }
        }
        if (b) count++;
        if ((sum == 7 || sum == 8)) {
            if (pre == count) cout << i << "\n";
        }
    }
    cout << count;
    return 0;
}
