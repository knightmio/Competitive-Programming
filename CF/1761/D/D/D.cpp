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

const int MOD = 1e9 + 7;
class Comb {
    vector<int> Facs, Invs;
public:
    Comb() : Facs({ 1 }), Invs({ 1 }) {}
    int operator() (int n, int k) {
        if (n == -1 && k == -1)return 1;
        if (n < k || k < 0) return 0;
        for (int i = Facs.size(), a, p, ans; i <= n; ++i) {
            Facs.push_back(1ll * Facs.back() * i % MOD);
            for (a = Facs[i], p = MOD - 2, ans = 1; p; p >>= 1, a = 1ll * a * a % MOD)
                if (p & 1) ans = 1ll * ans * a % MOD;
            Invs.push_back(ans);
        }
        return (1ll * Facs[n] * Invs[n - k] % MOD) * Invs[k] % MOD;
    }
};
Comb comb;

const int N = 1e6 + 5;
ll pw3[N];
int main()
{
    int n, k;
    cin >> n >> k;
    /*map<vector<int>, long long> cache;
    cache[{1, 1,0}] = 1;
    cache[{1, 0,0}] = 3;
    cache[{2, 2, 0}] = 3;
    cache[{2, 1, 0}] = 4;
    cache[{2, 0, 0}] = 9;
    cache[{1, 1, 1}] = 3;
    cache[{1, 0, 1}] = 1;
    cache[{2, 2, 1}] = 9;
    cache[{2, 1, 1}] = 4;
    cache[{2, 0, 1}] = 3;
    function<int(int, int, int)> help = [&](int n, int k, int carry) -> int {
        if (k < 0) return 0;
        if (n < k) return 0;
        if (cache.count({ n,k,carry })) return cache[{n, k, carry}];
        long long res = 0;
        if (carry == 0) {
            res += 3 * help(n - 1, k, 0);
            res %= 1000000007;
            res += help(n - 1, k-1, 1);
            res %= 1000000007;
        }
        else {
            res += help(n - 1, k, 0);
            res %= 1000000007;
            res += 3*help(n - 1, k - 1, 1);
            res %= 1000000007;
        }
        cout << n << " " << k << " " << carry << " " << res << "\n";
        return cache[{n, k, carry}] = (res %= 1000000007);
    };

    ll temp = pow(3, (n - 2)) * (n + 2);
    cout << help(n, k,0) << " " << temp % 1000000007;*/

    pw3[0] = 1;
    for (int i = 1; i < N; i++)pw3[i] = (3 * pw3[i - 1]) % MOD;
    ll ans = 0;
    for (int p = 0; p <= n; p++) {
        ans += (pw3[n - p] * comb(k-1, (p + 1) / 2 -1) % MOD * comb(n + 1 - k-1, (p + 1) - (p + 1) / 2 -1));
        ans %= MOD;
    }
    cout << ans << endl;

}