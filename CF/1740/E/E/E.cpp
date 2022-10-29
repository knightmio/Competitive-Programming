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
    int n;
    cin >> n;
    unordered_map<int, int> fa;
    unordered_map<int, vector<int>> child;

    fa[1] = 0;
    vector<int> indegrees(n + 1);
    rep(i, 2, n) {
        int temp;
        cin >> temp;
        child[temp].push_back(i);
        fa[i] = temp;
        indegrees[temp]++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2));
    queue<int> q;
    
    rep(i, 1, n) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }
    int res = 0;
    while (!q.empty()) {
        int sum = 0;
        int temp = q.front();
        q.pop();
        if (child.count(temp)) {
            int ma = 0;
            for (auto& a : child[temp]) {
                sum += dp[a][0];
                ma = max(ma, dp[a][0]);
            }
            if (child[temp].size() == 1) {
                dp[temp][0] = sum + 1;
                for (auto& a : child[temp]) {
                    dp[temp][1] = max(dp[temp][1], sum + dp[a][1] - dp[a][0]);
                }
            }
            else {
                //只留一个child node
                dp[temp][0] = ma + 1;
                //放弃自己
                dp[temp][1] = sum;
                for (auto& a : child[temp]) {
                    dp[temp][1] = max(dp[temp][1], dp[temp][1] + dp[a][1] - dp[a][0]);
                }
            } 
        }
        else {
            dp[temp][0] = 1;
            dp[temp][1] = 0;
        }
        indegrees[fa[temp]]--;
        if (indegrees[fa[temp]] == 0) q.push(fa[temp]);
        res = max(res, dp[temp][0]);
        res = max(res, dp[temp][1]);

    }
    cout << res;
}
