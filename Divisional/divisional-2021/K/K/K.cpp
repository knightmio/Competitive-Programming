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
    //贪心 只要能吃到下一个就先吃
    //吃不到下一个就去能吃到下一个的最近的点？->错的 很好举反例
    //↑bfs 不去vis过的点
    //如果有多个点就去能包括最多的点
    //如果都一样多呢？
    //最多只有9个candy
    //每个candy最多有多少子集？
    //9*2*10^5
    //dp题？
    //三维dp[i][j][k]
    //i表示吃到第几颗糖
    //j和k表示x坐标和右坐标？
    //如果jk不符合条件 设成INT_MAX/10
    //转移方程呢 每颗糖找上颗糖所有可能的合集 然后取最小值
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> dp(10, vector<int>(c*r, INT_MAX / 10));
    vector<vector<char>> input(r, vector<char>(c));
    unordered_map<int, pair<int, int>> mp;
    vector<unordered_set<int>> v(9);
    for (int i = 0; i < r; i++) {
        rep(j,0,c-1){
            cin >> input[i][j];
            if (isdigit(input[i][j])) {
                mp[input[i][j] - '0'] = { i,j };
            }
            if (input[i][j] == 'S') {
                mp[0] = { i,j };
            }
        }
    }
    rep(i, 1, 9) {
        int x = mp[i].first;
        int y = mp[i].second;
        v[i - 1].insert(x * c + y);
        rep(j, 1, k) {
            if (x + j == r) break;
            if (input[x + j][y] == '#')break;
            v[i-1].insert((x + j)* c+y);
        }
        rep(j, 1, k) {
            if (x - j < 0) break;
            if (input[x - j][y] == '#')break;
            v[i - 1].insert((x - j) * c + y);
        }
        rep(j, 1, k) {
            if (y + j == c) break;
            if (input[x][y + j] == '#')break;
            v[i - 1].insert(x  * c + y+j);
        }
        rep(j, 1, k) {
            if (y - j < 0) break;
            if (input[x][y - j] == '#')break;
            v[i - 1].insert(x * c + y - j);
        }
    }
    
    int start = 0;
    dp[0][mp[0].first * c + mp[0].second] = 0;
    rep(i, 1, 9) {
        int temp = mp[0].first * c + mp[0].second;
        if (v[i-1].count(temp)) {
            start++;
            dp[i][mp[0].first * c + mp[0].second] = 0;
        }
        else {
            break;
        }
    }
    //vector<vector<int>> vis(r, vector<int>(c));
    //unordered_map<unsigned long long, int> distance;
    //int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
    //function<int(int, int)> dis = [&](int start,int end) -> int {
    //    unsigned long long search = 1ull * start * 9977553311 + 1ull * end * 995511;
    //    unsigned long long search2 = 1ull * start * 995511 + 1ull * end * 9977553311;
    //    if (distance.count(search)) return distance[search];
    //    if (distance.count(search2)) return distance[search2];
    //    fill(vis.begin(), vis.end(), vector<int>(c,0));
    //    int sx = start / c;
    //    int sy = start % c;
    //    int ex = end / c;
    //    int ey = end % c;
    //    //cout << sx << " " << sy << " " << ex << " " << ey << "\n";
    //    int count = 0;
    //    vis[sx][sy] = 1;
    //    queue<pair<int, int>> q;
    //    q.push({ sx,sy });
    //    while (!q.empty()) {
    //        int len = q.size();
    //        while (len--) {
    //            int curx = q.front().first;
    //            int cury = q.front().second;
    //            q.pop();
    //            if (curx == ex && cury == ey) {
    //                return distance[search] = count;
    //            }
    //            rep(i, 0, 3) {
    //                int nx = curx + dx[i];
    //                int ny = cury + dy[i];
    //                if (nx >= 0 && nx < r && ny >= 0 && ny < c && input[nx][ny] != '#' && vis[nx][ny] == 0) {
    //                    q.push({ nx,ny });
    //                    vis[nx][ny] = 1;
    //                }
    //            }
    //        }
    //        count++;
    //    }
    //    return distance[search] = (INT_MAX / 10);
    //};
    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
    queue<vector<int>> q;
    q.push({ mp[0].first, mp[0].second,start});
    int res = 0;
    vector<vector<vector<int>>> vis(9, vector<vector<int>>(r, vector<int>(c)));
    while(!q.empty()){
        int len = q.size();
        while (len--) {
            auto a = q.front();
            q.pop();
            int location = a[0] * c + a[1];
            while (a[2]<9 && v[a[2]].count(location)) {
                a[2]++;
            }
            if (a[2] == 9) {
                cout << res + 9;
                return 0;
            }
            //上下左右四个位置
            rep(i, 0, 3) {
                int nx = a[0] + dx[i];
                int ny = a[1] + dy[i];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && input[nx][ny] != '#' && vis[a[2]][nx][ny] == 0) {
                    q.push({ nx,ny,a[2] });
                    vis[a[2]][nx][ny] = 1;
                }
            }
        }
        res++;
    }
    /*int res = INT_MAX;
    for (auto& a : v[8]) {
        res = min(res, dp[9][a]);
    }
    cout << res+9;*/
    return 0;
}
