#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()
const int MAXN = 310;
double dp[MAXN][MAXN][MAXN];

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1)a++;
        else if (x == 2)b++;
        else c++;
    }
    //double dp[305][305][305] = { 0 };
    
    function<double(int, int, int)> helper = [&](int x, int y, int z) -> double {
        double ret;
        if (x == 0 && y == 0 && z == 0) return 0;
        if (dp[x][y][z] > 0.0) return dp[x][y][z];
        //选到空的几率
        int sum = (x + y + z);
        ret = 1.0 * n / sum;
        if (x > 0) ret += 1.0 * x / sum * helper(x - 1, y, z);
        if (y > 0) ret += 1.0 * y / sum * helper(x + 1, y - 1, z);
        if (z > 0) ret += 1.0 * z / sum * helper(x, y + 1, z - 1);
        //cout << x << " " << y << " " << z << " " << ret << "\n";
        return dp[x][y][z] = ret;
    };

    double res = helper(a,b,c);
    cout << setprecision(14) << res;
    return 0;
}

