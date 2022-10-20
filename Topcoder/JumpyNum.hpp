#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <stdlib.h>

using namespace std;
class JumpyNum
{
  public:
  int helper(int low, int high, int current, int digit)
  {
    //cout << low  << "  " << high << "  " << current << "  " << digit << "  \n";
    //base case, we process all 10 possible digits in each run, so if cuurent > high/10 we finish this branch
    if (current > high/10){
      return 0;
    }else{
      int res = 0;
      current = current * 10;
      for (int i = 0; i < 10; ++ i){
        //cases are jumpy  - less or equal to boudary high
        if (abs(i - digit) >= 2 && current + i <= high){
          //lower boundary
          if(current + i >= low){
            res++;
          }
          res += helper(low, high, current + i, i);
        }
      }
      return res;
    }
  }

  int howMany(int low, int high)
  {
    return helper(low, high, 0, -1);
  }
};