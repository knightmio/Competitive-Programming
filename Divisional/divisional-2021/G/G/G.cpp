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
    unordered_set<char> s = {'A','E','I','O','U'};
    string word;
    cin >> word;
    if (s.count(word[0])) {
        cout << "no";
        return 0;
    }
    rep(i, 1, word.size() - 1) {
        if (s.count(word[i])){
            if (word[i - 1] == 'L' || word[i - 1] == 'G') {
                continue;
            }else{
                cout << "no";
                return 0;
            }
        }
    }
    cout << "yes";
    return 0;
}
