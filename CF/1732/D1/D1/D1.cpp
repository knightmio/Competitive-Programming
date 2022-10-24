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
    int q;
    cin >> q;
    map<ll, int>vis;
    map<ll, ll>last;
    rep(i, 0, q - 1) {
        string a;
        ll b;
        cin >> a >> b;
        if (a == "+") {
            vis[b] = 1;
        }
        else {
            if (!last.count(b))last[b] = b;
            while (vis[last[b]])last[b] += b;
            cout << last[b] << endl;
        }
    }
}
//#include<iostream>
//#include <cstdlib>
//#include<bits/stdc++.h>
//#include <unordered_map>
//using namespace std;
//#define LL long long
//#define ll LL
//#define vll vector<ll>
//#define rep(i,a,b) for(int i=(a);i<=(b);++i)
//#define all(_obj) _obj.begin(), _obj.end()
//
//int main()
//{
//    int q;
//    cin >> q;
//    set<ll> s;
//    s.insert(0);
//    map<ll, ll> mp;
//    rep(i, 0, q - 1) {
//        string a, b;
//        cin >> a >> b;
//        if (a == "+") {
//            s.insert(stoll(b));
//        }
//        else {
//            ll mult = 1;
//            ll bb = stoll(b);
//            if (mp.count(bb)) mult = mp[bb];
//            while (s.count(bb * mult)) mult++;
//            mp[bb] = mult;
//            cout << bb * mult << "\n";
//        }
//    }
//}