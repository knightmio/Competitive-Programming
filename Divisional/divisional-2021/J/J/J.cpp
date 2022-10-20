#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define LL long long
#define ll LL

using namespace std;
const int mod = 1000000007;
const int maxn = 26;///只有4个字母
const int N = 1e3 + 3;
struct ac {
    int trie[N][maxn], fail[N];
    int tot, root;
    bool end[N];
    ll res[N][N], ans[N][N], tmp[N][N];
    int newnode() {
        for (int i = 0; i < maxn; i++) {
            trie[tot][i] = -1;
        }
        end[tot++] = 0;
        return tot - 1;
    }
    void init() {
        tot = 0;
        root = newnode();
        memset(res, 0, sizeof(res));
        memset(ans, 0, sizeof(ans));
        memset(end, false, sizeof(end));
    }

    void insert(string buf, int id) {
        int now = root, len = buf.size();
        for (int i = 0; i < len; i++) {
            int x = buf[i] - 'a';
            if (trie[now][x] == -1)
                trie[now][x] = newnode();
            now = trie[now][x];
        }
        end[now] = true;//它的路径字符串本身就是一个不良单词 
    }
    void getfail() {

        queue<int>que;
        while (!que.empty())
            que.pop();
        fail[root] = root;
        for (int i = 0; i < maxn; i++)
            if (trie[root][i] == -1)
                trie[root][i] = root;
            else {
                fail[trie[root][i]] = root;
                que.push(trie[root][i]);
            }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            if (end[fail[now]])//它的路径字符串的后缀对应的结点（即fail[i]）是危险结点 
                end[now] = true;
            for (int i = 0; i < maxn; i++) {
                if (trie[now][i] != -1) {
                    fail[trie[now][i]] = trie[fail[now]][i];
                    que.push(trie[now][i]);
                }
                else
                    trie[now][i] = trie[fail[now]][i];
            }
        }
    }

    void path() {
        for (int i = 0; i < tot; i++) {
            for (int j = 0; j < maxn; j++)
                if (!end[i] && !end[trie[i][j]]) {
                    //    cout<<i<<"!!"<<j<<endl;
                    res[i][trie[i][j]]++;
                }

        }
    }
    void mul(ll a[][N], ll b[][N]) {
        for (int i = 0; i < tot; i++)
            for (int j = 0; j < tot; j++) {
                tmp[i][j] = 0;
                for (int k = 0; k < tot; k++)
                    tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
            }
        for (int i = 0; i < tot; i++)
            for (int j = 0; j < tot; j++)
                a[i][j] = tmp[i][j];
    }
    ll solve(ll n) {

        for (int i = 0; i < tot; i++)
            ans[i][i] = 1;
        while (n) {
            if (n & 1) {
                mul(ans, res);
            }
            n >>= 1;
            mul(res, res);
        }
        ll ANS = 0;
        for (int i = 0; i < tot; i++)
            ANS = (ANS + ans[0][i]) % mod;
        return ANS;
    }
}AC;
char s[110];
int main() {
    int n;
    ll k;
    cin >> n >> k;
    AC.init();
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        AC.insert(s, i);
    }
    AC.getfail();
    AC.path();
    printf("%lld\n", AC.solve(k));
    return 0;
}