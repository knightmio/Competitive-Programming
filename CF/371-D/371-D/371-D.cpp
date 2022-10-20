#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
#define pb(s) push_back(s);
#define ms(s) memset(s, 0, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 2000010;

int n, m;
//b记录每个已经有多少水
LL a[N], b[N];
struct UF {
	std::vector<int> f, siz;
	UF(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
	int find(int x) {
		while (x != f[x]) x = f[x] = f[f[x]];
		return x;
	}
	bool same(int x, int y) { return find(x) == find(y); }
	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	int size(int x) { return siz[find(x)]; }
};
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	UF uf(N);
	int z, x, y;
	for (int i = 0; i < m; ++i) {
		cin >> z;
		if (z == 1) {
			cin >> x >> y;
			x = uf.find(x);
			while (y > 0 && x <= n) {
				x = uf.find(x);
				//可装满
				if (y >= (a[x] - b[x])) {
					y -= (a[x] - b[x]);
					b[x] = a[x];
					uf.merge(x + 1, x);
				}
				else {
					//不可装满
					b[x] += y;
					break;
				}
			}
		}
		else {
			cin >> x;
			cout << b[x] << '\n';
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
