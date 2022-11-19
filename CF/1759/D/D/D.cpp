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
        ll n, m;
        cin >> n >> m;
        ll temp = n;
        int twos = 0;
        int fives = 0;
        while (n % 2 == 0) {
            twos++;
            n /= 2;
        }
        while (n % 5 == 0) {
            fives++;
            n /= 5;
        }
        priority_queue<pair<int, long long>> pq;
        if (fives > twos) {
            long long start = 1;
            for (int j = 0; j <= (fives - twos); j++) {
                if (start > m) break;
                pq.push({ twos +j,m / start * start * temp });
                ll temp2 = start;
                int count = 0;
                while (temp2 * 10 <= m) {
                    temp2 *= 10;
                    count++;
                    pq.push({ twos +j+count,m / temp2 * temp2 * temp });
                    //cout << twos + j + count << "\n";
                }
                start *= 2;

            }
        }
        else if(fives < twos){
            long long start = 1;
            for (int j = 0; j <= abs(fives - twos); j++) {
                if (start > m) break;
                pq.push({ fives + j,m / start * start * temp });
                //cout << fives + 1 + j << " " << m / start * start * temp << "\n";
                ll temp2 = start;
                int count = 0;
                while (temp2 * 10 <= m) {
                    temp2 *= 10;
                    count++;
                    pq.push({ fives + j + count,m / temp2 * temp2 * temp });
                }
                start *= 5;
            }
        }
        else {
            long long temp2 = 1;
            pq.push({ 0, m * temp });
            int count = 0;
            while (temp2 * 10 <= m) {
                temp2 *= 10;
                count++;
                pq.push({ count,m / temp2 * temp2 * temp });
            }
        }
        /*while (!pq.empty()) {
            cout << pq.top().first << " " << pq.top().second << "\n";
            pq.pop();
        }*/
        cout << pq.top().second << "\n";
    }
}
