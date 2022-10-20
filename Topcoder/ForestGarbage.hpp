#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
#define FOR(a) for(int i=0;i<=a;i++)
class ForestGarbage
{
  public:
  int res[50][50];
  int cost[50][50];
  void reset(int res[50][50]){
    for(int i = 0; i< 50;i++){
        for(int j = 0; j< 50;j++){
            res[i][j] =0;
        }
    }
  }

  void calculate (int res[50][50],int cost[50][50], int row, int col){
    //cout << "test test " << !finish(res,row,col) <<"\n";
    int count = 0;
      while(count < row * col){
        for(int i = 0; i< row-1;i++){
            for(int j = 0; j< col;j++){
                if(res[i][j]>res[i+1][j]+cost[i][j]) res[i][j]= res[i+1][j]+cost[i][j];
            }
        }
        for(int i = 1; i< row;i++){
            for(int j = 0; j< col;j++){
                if(res[i][j]>res[i-1][j]+cost[i][j]) res[i][j]= res[i-1][j]+cost[i][j];
            }
        }
        for(int i = 0; i< row;i++){
            for(int j = 0; j< col-1;j++){
                if(res[i][j]>res[i][j+1]+cost[i][j]) res[i][j]= res[i][j+1]+cost[i][j];
            }
        }
        for(int i = 0; i< row;i++){
            for(int j = 1; j< col;j++){
                if(res[i][j]>res[i][j-1]+cost[i][j]) res[i][j]= res[i][j-1]+cost[i][j];
            }
        }
        count++;
      }

  }

  int best(vector<string> forest)
  {
    // your code for the problem
    reset(res);
    reset(cost);
    int x = 0;
    int y = 0;

    int row = forest.size();
    int col = forest.at(0).length();
    //cout << row << "  "<< col << "\n";
    for(int i = 0; i< row;i++){
        string temp = forest.at(i);
        for(int j = 0; j< col;j++){
            res[i][j] = 999999;
            if(temp[j] == 'g') cost[i][j] = 10000;
            if ((i>0 && forest.at(i-1).at(j)=='g') || (i<row-1 && forest.at(i+1).at(j)=='g') || (j>0 && forest.at(i).at(j-1)=='g') || (j<col-1 && forest.at(i).at(j+1)=='g')){
              if(cost[i][j] != 10000) cost[i][j] = 1;
            }
            if(temp[j] == 'S') res[i][j] = 0;
            if(temp[j] == 'F'){
              cost[i][j] = 0;
              x = i;
              y =j;
            }

        }
    }
    calculate(res,cost,row,col);
    return res[x][y];
  }

  vector<int> bestWay(vector<string> forest){
      int temp = best(forest);
      vector<int> res;
      res.push_back(temp/10000);
      res.push_back(temp%10000);
      return res;
  }

};
