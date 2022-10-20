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
    vector<string> input(n);
    rep(i, 0, n - 1) cin >> input[i];
    int line = 0;
    rep(i, 0, n - 1) {
        string temp;

        temp = input[i];
        //if(line == i)cout << i << " " << temp << "\n";line++;
        if (temp[0] == 'h' && temp[1] == 'i') {
            int count = 0;
            for (int j = 2; j < temp.size(); j++) {
                if (temp[j] != 's') {
                    if(line == i)cout << "human noises\n";line++;
                }
                else {
                    count++;
                }
            }
            if (count >= 2) {
                if(line == i)cout << "hiss\n";line++;
            }
            else {
                if(line == i)cout << "human noises\n";line++;
            }
        }
        else if (temp[0] == 't' && temp[1] == 'r') {
            int count = 0;
            int idx = 2;
            while (temp[idx] == 'i') {
                count++;
                idx++;
            }
            if (count == 0) {
                if(line == i)cout << "human noises\n";line++;
            }
            else {
                count = 0;
                while (temp[idx] == 'l') {
                    count++;
                    idx++;
                }
                if (idx != temp.size() || count < 2) {
                    if(line == i)cout << "human noises\n";line++;
                }
                else {
                    if(line == i)cout << "trill\n";line++;
                }
            }
        }
        else if (temp[0] == 'b') {
            int count = 0;
            int idx = 1;
            while (temp[idx] == 'u') {
                count++;
                idx++;
            }
            if (count == 0) {
                if(line == i)cout << "human noises\n";line++;
            }
            else {
                count = 0;
                while (temp[idx] == 'r') {
                    count++;
                    idx++;
                }
                if (count == 0) {
                    if(line == i)cout << "human noises\n";line++;
                }
                else {
                    if (temp[idx] != 'b') {
                        if(line == i)cout << "human noises\n";line++;
                    }
                    else {
                        idx++;
                        count = 0;
                        while (temp[idx] == 'l') {
                            count++;
                            idx++;
                        }
                        if (count == 0) {
                            if(line == i)cout << "human noises\n";line++;
                        }
                        else {
                            if (temp[idx] == 'e' && idx == temp.size() - 1) {
                                if(line == i)cout << "burble\n";line++;
                            }
                            else {
                                if(line == i)cout << "human noises\n";line++;
                            }
                        }
                    }
                }
            }
        }
        else {
            if(line == i)cout << "human noises\n";line++;
        }
    }
    return 0;
}