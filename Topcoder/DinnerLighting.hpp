#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <sstream>

using namespace std;


class DinnerLighting
{
  public:

  int	countDarkSquares (int	R,	int	C,	vector<string> roomPlan){
      int res = 0;
      bool light[50][50];
      for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
          light[i][j] = false;
        }
      }

      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
                    string temp = roomPlan[i];
          if(temp[j] == 'O'){
            light[i][j] = true;
            for(int k = j+1; k < C;k++){
              if(temp[k] != '#') light[i][k] = true;
              if(temp[k] == '#') break;
            }
            for(int k = j-1; k >= 0;k--){
              if(temp[k] != '#') light[i][k] = true;
              if(temp[k] == '#') break;
            }
            for(int k = i+1; k < R;k++){
              temp = roomPlan[k];
              if(temp[j] != '#') light[k][j] = true;
              if(temp[j] == '#') break;
            }
            for(int k = i-1; k >= 0;k--){
              temp = roomPlan[k];
              if(temp[j] != '#') light[k][j] = true;
              if(temp[j] == '#') break;
            }
          }
          if(temp[j] == '#')light[i][j] = true;
        }
      }

      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << light[i][j] <<"  ";
          if(!light[i][j]) res++;
        }
        //cout << "\n";
      }
      return res;
  }
};
