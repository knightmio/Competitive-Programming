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
        string s;
        cin >> n >> s;

        vector<int> sum(2 * n + 1);
        rep(j, 1, 2 * n) {
            sum[j] = sum[j - 1] + (s[j - 1] == '(' ? 1 : -1);
        }

        if (*min_element(sum.begin(), sum.end()) == 0) {
            cout << 0 << '\n';
        }
        else {
            int l = 0, r = 2 * n;
            while (sum[l + 1] >= 0) {
                l += 1;
            }
            while (sum[r - 1] >= 0) {
                r -= 1;
            }
            l = (int)(max_element(sum.begin(), sum.begin() + l + 1) - sum.begin());
            r = (int)(max_element(sum.begin() + r, sum.end()) - sum.begin());
            //cout << l << " " << r << "\n";

            reverse(s.begin() + l, s.begin() + r);
            //cout << s;
            int count = 0;
            rep(j, 1, 2 * n) {
                count += (s[j - 1] == '(' ? 1 : -1);
                if (count < 0) {
                    int idx = (int)(max_element(sum.begin(), sum.end()) - sum.begin());
                    cout << "2\n";
                    cout << "1 " << idx << "\n";
                    cout << idx + 1 << " " << 2 * n << "\n";
                    break;
                }
                if (j == 2 * n) {
                    cout << "1\n";
                    cout << l+1 << " " << r << "\n";
                }
            }
        }
    }
}