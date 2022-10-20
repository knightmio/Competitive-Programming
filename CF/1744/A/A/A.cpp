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
        int n;
        cin >> n;
        int rest = n;
        rep(j, 0, n - 1) {
            int temp;
            cin >> temp;
            while (temp % 2 == 0) {
                temp /= 2;
                rest--;
            }
        }
        if (rest <= 0) {
            cout << "0" << "\n";
        }else{
            int op = 0;
            int largest = 2;
            int contri = 1;
            int pre = 1;
            while (largest <= n) {
                largest *= 2;
                contri++;
            }
            largest /= 2;
            contri--;
            int left = n / largest;
            while (rest > 0 && largest > 1) {
                rest -= contri;
                op++;
                left--;
                if (left == 0) {
                    contri--;
                    largest /= 2;
                    left = n / largest - pre;
                    pre += left;
                }
            }
            if (rest <= 0) {
                cout << op << "\n";
            }else{
                cout << "-1\n";
            }
        }
    }
    return 0;
}
