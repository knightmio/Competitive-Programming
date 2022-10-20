#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class KokoBananas
{
  public:
   int lastHand(vector<int> hands, int K)
  {
    // your code for the problem
    int res =0;
    while (K > 0){
      int max = *max_element(hands.begin(),hands.end());
      cout << max << " ";
      for(int i =0; i < hands.size();i++){
        if(hands.at(i) == max){
          hands.at(i)--;
          if(K ==1) res = i;
          i = hands.size();
        }

      }
      K--;
    }

    return res;
  }
};
