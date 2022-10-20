#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;


class CatGame
{
  public:
  int res;

  int minDiff(vector<int> temp){
      int max = *max_element(temp.begin(), temp.end());
      int min = *min_element(temp.begin(), temp.end());
      return max - min;
  }

  void helper(vector<int> max, vector<int> min){
    int size = max.size();
    for(int i = 0; i < size; i++){
      vector<int> temp;
      for(int j = 0; j < i; j++){
        temp.push_back(max.at(j));
      }
      for(int j = i; j < size; j++){
        temp.push_back(min.at(j));
      }
      if (minDiff(temp) < res) res = minDiff(temp);
    }
  }

  int getNumber(vector<int> coordinates, int X){
      res = INT_MAX;
      vector<int> max;
      vector<int> min;
      sort(coordinates.begin(), coordinates.end());
      for(int i = 0; i < coordinates.size(); i++){
        max.push_back(coordinates.at(i) + X);
        min.push_back(coordinates.at(i) - X);
      }

      helper(max,min);

      return res;
  }
};
