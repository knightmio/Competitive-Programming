#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    int m, n, x;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    rep(i, 1, n) cin >> a[i - 1];
    rep(i, 1, m) cin >> b[i - 1];
    cin >> x;
	//求前缀和
	vector<int> prex1(n + 1), prex2(m + 1);
	for (int i = 1; i <= n; i++)prex1[i] = a[i - 1] + prex1[i - 1];
	for (int i = 1; i <= m; i++)prex2[i] = b[i - 1] + prex2[i - 1];


	vector<ll> c(n + 1, INT_MAX);
	//通过前缀和快速求某个长度的最小和
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j + i - 1 <= n; j++) {
			c[i] = min(c[i], 1ll * prex1[j + i - 1] - prex1[j - 1]);
		}
	}
	//对于列是同样的处理方式
	vector<ll> d(m + 1, INT_MAX);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j + i - 1 <= m; j++) {
			d[i] = min(d[i], 1ll * prex2[j + i - 1] - prex2[j - 1]);
		}
	}

	int ans = 0;
	//如果c*d不超过x就说明这个矩阵符合条件 更新max
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i] * d[j] <= x)ans = max(ans, i * j);
		}
	}
	cout << ans << endl;

	return 0;
}