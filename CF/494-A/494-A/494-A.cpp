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
    //(((#)((#)
    //1 2 3 ? 2 3 4 ? 3
    //至少要替换成1个？
    //1 2 3 2 1 2 3 2 1
    //1 2 / 2 1都是合法解
    //那某一个x的值就等于1 + 到下个x中间的最小值？ 单调栈?
    //((#)( 经典反例 在任何一个#的位置最多只能多放count个)
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
            cout << "-1" << endl;
            return 0;
        }
    }
    if (min_d < count) {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 0; i < num - 1; i++) {
        cout << "1" << endl;
    }
    cout << 1 + count << endl;
    //system("pause");
    return 0;
}