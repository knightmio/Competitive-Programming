#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <sstream>

using namespace std;


class CaveExpedition
{
  public:
  int dis[50][50];
  bool travelled[50][50];
  void dijkstra(int sx,int sy, int dx, int dy, vector	<string> caveMap){
    int x = caveMap.size();
    int y = caveMap[0].length();
    int curx = sx;
    int cury = sy;
    int distance = 0;
    travelled[sx][sy] = true;
    while(!travelled[dx][dy]){
      if(curx-1 >= 0 && dis[curx-1][cury] > distance + caveMap[curx-1][cury] - '0' && !travelled[curx-1][cury]) dis[curx-1][cury] = distance + caveMap[curx-1][cury] - '0';
      if(cury-1 >= 0 && dis[curx][cury-1] > distance + caveMap[curx][cury-1] - '0' && !travelled[curx][cury-1]) dis[curx][cury-1] = distance + caveMap[curx][cury-1] - '0';
      if(curx+1 <x && dis[curx+1][cury] > distance + caveMap[curx+1][cury] - '0' && !travelled[curx+1][cury]) dis[curx+1][cury] = distance + caveMap[curx+1][cury] - '0';
      if(cury+1 <y && dis[curx][cury+1] > distance + caveMap[curx][cury+1] - '0' && !travelled[curx][cury+1]) dis[curx][cury+1] = distance + caveMap[curx][cury+1] - '0';
      int temp = INT_MAX;



      for(int i = 0 ; i < caveMap.size(); i++){
        for(int j = 0 ; j < caveMap[0].length(); j++){
          if(!travelled[i][j] && dis[i][j] < temp){
            temp = dis[i][j];
            curx = i;
            cury = j;
          }
        }
      }
      travelled[curx][cury] = true;
      distance = temp;
    }
  }

  int	bestPath(vector	<string> caveMap){
      int sx,sy,dx,dy;
      for(int i = 0 ; i < 50; i++){
        for(int j = 0 ; j < 50; j++){
          dis[i][j] = INT_MAX;
          travelled[i][j] = false;
        }
      }

      for(int i = 0 ; i < caveMap.size(); i++){
        for(int j = 0 ; j < caveMap[0].length(); j++){
          if(caveMap[i][j] == 'S'){
            sx = i;
            sy = j;
          }
          if(caveMap[i][j] == 'D'){
            dx = i;
            dy = j;
          }
        }
      }
      dijkstra( sx, sy, dx, dy, caveMap);

      return (dis[dx][dy] - 20);
  }
};
