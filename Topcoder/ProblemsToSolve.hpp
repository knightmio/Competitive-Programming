#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class ProblemsToSolve
{
  public:
  int minNumber(vector<int> pleasantness, int variety){
    int max = pleasantness.size();
    for (int i = 0; i<pleasantness.size(); i++){
      for (int j=i+1; j<pleasantness.size();j++){
        if (abs(pleasantness[j]-pleasantness[i]) >= variety){
            int res = 2;
            if (i>0) res += (i+1)/2;
            res += (j-i-1)/2;
            if (res<max) max = res;
        }
      }
    }

    return max;
  }
};
