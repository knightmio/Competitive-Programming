#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <sstream>

using namespace std;


class ClubAdmission
{
  public:

  int bestSum(vector<int> card){
      int res = 0;
      int max = 0;
      for (int i = 0; i < card.size(); i++){
        res += card[i];
        if(card[i] < 10){
          if(max < 9 - card[i]) max = 9 - card[i];
        }else{
          if(max < 9 - (card[i] - (card[i]/10)*10)) max = 9 - (card[i] - (card[i]/10)*10);
          if(max < 90 - (card[i]/10)*10) max = 90 - (card[i]/10)*10;
        }
      }
      return res+max;
  }
};
