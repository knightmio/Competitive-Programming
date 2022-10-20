#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;


class CellRemoval
{
  public:
  queue<int> index;
  int res;

  int cellsLeft(vector<int> parent, int deletedCell){
      while(!index.empty()){
          index.pop();
      }
      res = 0;

      for(int i = 0; i < parent.size(); i++){
        if(parent.at(i) == -1){
            index.push(i);
            i = INT_MAX;
        }
      }

      while(!index.empty()){
          int temp = index.front();
          index.pop();
          bool child = true;
          if(temp != deletedCell){
            for(int i = 0; i < parent.size(); i++){
                if(parent.at(i) == temp){
                    child = false;
                    index.push(i);
                }
            }
            if(child) res++;
          }
      }

      return res;
  }
};
