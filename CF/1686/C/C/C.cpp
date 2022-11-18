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


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& e : arr) {
        cin >> e;
    }
    if (n & 1) {
        cout << "NO\n";
        return;
    }
    sort(all(arr));
    vector<int> res;
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[i + n / 2]) {
            cout << "NO\n";
            return;
        }
        res.push_back(arr[i]);
        res.push_back(arr[i + n / 2]);
    }
    for (int i = 0; i + 1 < n; i++) {
        if (res[i] == res[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int e : res) {
        cout << e << " ";
    }
    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
