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
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int a, b, ab, ba;
        string s;
        cin >> a >> b >> ab >> ba >> s;
        int counta = 0;
        int countb = 0;
        for (char& c : s) {
            if (c == 'A') {
                counta++;
            }
            else {
                countb++;
            }
        }
        if (counta != a + ab + ba || countb != b + ab + ba) {
            cout << "NO\n";
        }
        else {
            priority_queue<int, vector<int>, greater<int>> pqab;
            priority_queue<int, vector<int>, greater<int>> pqba;

            int len = 1;
            char pre = s[0];
            int free = 0;
            for (int j = 1; j < s.size(); j++) {
                if (s[j] == pre) {
                    if (len > 1) {
                        if (len % 2 == 0) {
                            if (pre == 'B') { 
                                pqab.push(len / 2);
                            }else{
                                pqba.push(len / 2);
                            }
                        }
                        else {
                            //奇数 free加len/2
                            free += len / 2;
                        }
                    }
                    len = 1;
                }else{
                    len++;
                }
                pre = s[j];
            }
            if (len > 1) {
                if (len % 2 == 0) {
                    if (pre == 'B') {
                        pqab.push(len / 2);
                    }
                    else {
                        pqba.push(len / 2);
                    }
                }
                else {
                    //奇数 free加len/2
                    free += len / 2;
                }
            }
            while (!pqab.empty()) {
                int temp = pqab.top();
                pqab.pop();
                if (ab >= temp) {
                    ab -= temp;
                }
                else {
                    free += temp - 1;
                }
            }
            while (!pqba.empty()) {
                int temp = pqba.top();
                pqba.pop();
                if (ba >= temp) {
                    ba -= temp;
                }
                else {
                    free += temp - 1;
                }
            }
            if(free >= ba + ab){
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}
