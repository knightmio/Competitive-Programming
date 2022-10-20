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
    //贪心bfs？
    int m, n;
    cin >> n >> m;
    vector<vector<char>> input(m, vector<char>(n));
    queue<int> neg;
    rep(i, 0, m - 1) {
        rep(j, 0, n - 1) {
            cin >> input[i][j];
            if (input[i][j] == 'P') neg.push(i * n + j);
        }
    }
    vector<vector<int>> val(m, vector<int>(n));
    rep(i, 0, m - 1) {
        rep(j, 0, n - 1) cin >> val[i][j];
    }
    vector<vector<int>> vis(m, vector<int>(n));
    vector<int> fa(n* m);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> pq;
    int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int res = 0;
    int route = 0;
    while (!neg.empty()) {
        route++;
        int temp = neg.front();
        neg.pop();
        int x = temp / n;
        int y = temp % n;
        //cout << x << " " << y << "\n";
        vis[x][y] = route;
        res = max(val[x][y], res);
        while (!pq.empty()) pq.pop();

        rep(i, 0, 3) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (vis[nx][ny] != 0) {
                    while (!pq.empty()) pq.pop();
                    break;
                }
                pq.push({ val[nx][ny], nx * n + ny });
                //cout << nx << " " << ny << "\n";
            }
        }
        //cout << pq.size() << "\n";

        while (!pq.empty()) {
            int xx = pq.top().second / n;
            int yy = pq.top().second % n;
            //cout << xx << " " << yy << "\n";
            vis[xx][yy] = route;
            pq.pop();
            res = max(val[xx][yy], res);
            if (input[xx][yy] == 'N')break;
            rep(i, 0, 3) {
                int nx = xx + dir[i][0];
                int ny = yy + dir[i][1];
                //cout << xx << " " << yy << " " << nx << " " << ny << "\n";
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if ((vis[nx][ny] != 0 && vis[nx][ny] != route)) {
                        while (!pq.empty()) {
                            pq.pop();
                        }
                        break;
                    }
                    if(vis[nx][ny] != route) pq.push({ val[nx][ny], nx * n + ny });
                }
            }
        }
    }
    cout << res;
    return 0;
}
