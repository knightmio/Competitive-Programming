
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
//d1表示上下左右
//d2表示斜线移动
int dx1[4] = { 1,-1,0,0 };
int dy1[4] = { 0,0,1,-1 };
int dx2[4] = { 1,1,-1,-1 };
int dy2[4] = { 1,-1,1,-1 };

int main()
{
    //仙人掌数量要最少
    //为什么这是个最短路问题啊？
    //啊 实际上变成了从第一列任意一个节点到最后一列任意一个节点的最小cost
    //cost由需不需要种仙人掌决定？
    //为什么可以用01bfs？deque模拟优先队列
    int t;
    cin >> t;
    rep(i, 0, t - 1) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        rep(j, 0, n - 1) {
            string temp;
            cin >> temp;
            rep(k, 0, m - 1) {
                grid[j][k] = temp[k];
            }
        }
        //检验能否放置仙人掌
        auto check = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m)return false;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx1[k], ny = y + dy1[k];
                //这里不需要考虑越界吗？
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (grid[nx][ny] == '#')return false;
            }
            return true;
        };
        vector<vector<int>> dp(n, vector<int>(m,-1));


        //双端队列bfs的部分？
        //deque存个pair?
        deque<pair<int, int>> q;
        //初始化 把所有第一列的都存了
        //如果值是1 表示这里一开始没有仙人掌 也不能增加仙人掌 所以不能作为起始点？
        rep(j, 0, n - 1) {
            if (grid[j][0] == '#') {
                q.push_front({ j,0 });
                dp[j][0] = 0;
            }
            else if (check(j,0)) { 
                q.push_back({ j,0 });
                dp[j][0] = 1;
            }
        }
        //记录path
        map<pair<int, int>, pair<int, int>>pre;//前驱

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop_front();
            rep(j, 0, 3) { 
                //斜着走只是单纯因为仙人掌没法连着
                int nx = x + dx2[j], ny = y + dy2[j];
                //判断越界 能否植仙人掌
                if (!check(nx, ny))continue;
                //不太懂这一句 难道已经被访问过的节点不存在一条更短的路径吗？
                //哦...我们是01bfs 一定是路径最短的那条先被算到
                if (dp[nx][ny] != -1)continue;
                if (grid[nx][ny] == '#') {
                    //不需要种
                    dp[nx][ny] = dp[x][y];
                    q.push_front({ nx, ny });
                    //记录path？
                    pre[{nx, ny}] = { x,y };
                    /*cout <<"cur : " << x << " " << y << "\n";
                    cout << "next : " << nx << " " << ny << " " << dp[nx][ny] << "\n";*/
                }
                else {
                    //需要种
                    dp[nx][ny] = dp[x][y]+1;
                    q.push_back({ nx, ny });
                    //记录path？
                    pre[{nx, ny}] = { x,y };
                    /*cout << "cur : " << x << " " << y << " " << dp[x][y] << "\n";
                    cout << "next : " << nx << " " << ny << " " << dp[nx][ny] << "\n";*/
                }
            }
        }

        int len = INT_MAX;
        pair<int, int> destination;
        rep(j, 0, n - 1) {
            if (dp[j][m - 1] != -1 && dp[j][m - 1] < len) {
                len = dp[j][m - 1];
                destination = { j,m - 1 };
            }
        }
        if (len == INT_MAX) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            while (pre.count(destination)) { 
                grid[destination.first][destination.second] = '#';
                destination = pre[destination];
            }
            grid[destination.first][destination.second] = '#';
            rep(j, 0, n - 1) {
                rep(k, 0, m - 1) {
                    cout << grid[j][k];
                }
                cout << "\n";
            }
        }
    }
    //cout << "end?";
    return 0;
}
