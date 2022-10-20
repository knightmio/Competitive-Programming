#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <sstream>

using namespace std;


class LemonGate
{
  public:
    int helper(int index, vector <int> lemons){
    int res = 0;
    int max = 0;
    if (index >= lemons.size()){
      return 0;
    }
    res += lemons[index];
    for(int i = index + 2; i < index + 4;i++){
      int temp = helper(i, lemons);
              //cout <<"next index " << i << " with value " << temp << "\n";
      if (temp > max) max = temp;
    }
    return max + res;
  }

  int	maxNumber(vector <int> lemons){
      int max = 0;
      for(int i = 0; i < 2;i++){
        int temp = helper(i, lemons);

        if(temp > max) max = temp;
      }
      return max;
  }
};
