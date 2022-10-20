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
    vector<string> name(4);
    string str;
    rep(i, 0, 3) {
        getline(cin, str);
        name[i] = str;
    }
    int pot;
    cin >> pot;
    vector<int> score1(4);
    int temp;
    rep(i, 0, 7) {
        cin >> temp;
        if (temp == 0) pot += 250;
        if(i < 4)score1[i % 4] += temp;
        if (i >= 4)score1[7-i] += temp;

        //cout << i << " ";
    }
    int index = -1;
    int ma = -1;
    rep(i, 0, 3) {
        if (score1[i] > ma) {
            ma = score1[i];
            index = i;
        }
    }
    cout << "Round 1: " << name[index] << " are eliminated.\n";
    name.erase(name.begin() + index);
    vector<int> score2(3);
    rep(i, 0, 5) {
        cin >> temp;
        if (temp == 0) pot += 250;
        if (i < 3)score2[i % 3] += temp;
        if (i >= 3)score2[5 - i] += temp;
    }
    ma = -1;
    int index2 = -1;
    rep(i, 0, 2) {
        if (score2[i] > ma) {
            ma = score2[i];
            index2 = i;
        }
    }
    cout << "Round 2: " << name[index2] << " are eliminated.\n";
    cout << "Jackpot is GBP" << pot << ".";
    return 0;
}
