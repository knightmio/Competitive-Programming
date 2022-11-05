#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
#include <map>

using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
const int maxn = 2e5 + 5;
int a[maxn], s[maxn];
int cnt[maxn], nxt[maxn], pre[maxn];
int ans[maxn];

int main()
{
    /*区间异或和不为0, 答案为-1.
    区间内已经全是0, 答案为0.
    区间长度为奇数, 只需操作整个区间, 答案为1.
    否则区间长度一定是偶数, 若最左边/最右边为0, 那么只需要操作剩余部分即可, 答案为1.
    如果区间有前缀或者后缀的异或和为0, 只需先操作前缀或者后缀后再操作整个区间即可, 答案为2.
    其他情况, 答案为-1.*/
    //区间xor可以用On大小的前缀和判断
    //全是0可以On判断
    //长度判断r-l+1 O1
    //最左最右O1判断
    //前缀或后缀的亦或和部分要预处理 不然最坏On^2超时
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    map<int, int> last[2];
    last[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = -1;
        nxt[i] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = (s[i - 1] ^ a[i]);
        cnt[i] = cnt[i - 1] + (a[i] > 0);
        int bit = i & 1;
        if (last[bit ^ 1].count(s[i])) {
            int lastpos = last[bit ^ 1][s[i]];
            pre[i] = lastpos + 1;
            nxt[lastpos + 1] = min(nxt[lastpos + 1], i);
        }
        last[bit][s[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        int x = s[r] ^ s[l - 1];
        if (x != 0) {
            ans[i] = -1;
            continue;
        }
        if (cnt[r] - cnt[l - 1] == 0) {
            ans[i] = 0;
            continue;
        }
        if ((r - l + 1) % 2 == 1) {
            ans[i] = 1;
            continue;
        }
        if (a[l] == 0 || a[r] == 0) {
            ans[i] = 1;
            continue;
        }
        if (nxt[l] <= r || pre[r] >= l) {
            ans[i] = 2;
            continue;
        }
        ans[i] = -1;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';

}