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
        int m, n, k;
        cin >> m >> n >> k;
        vector<int> input(k);
        rep(j, 0, k - 1) cin >> input[j];
        int cur = k;
        int f = n * m - 2;
        priority_queue<int> pq;
        bool b = true;
        for (int j = 0; j < k; j++) {
            if (input[j] == cur) {
                cur--;
                while (!pq.empty() && pq.top() == cur) {
                    cur--;
                    f++;
                    pq.pop();
                }
            }else{
                pq.push(input[j]);
                f--;
                if (f < 2) {
                    b = false;
                    break;
                }
            }

        }
        if (b) {
            cout << "YA\n";
        }
        else {
            cout << "TIDAK\n";
        }
    }
}
