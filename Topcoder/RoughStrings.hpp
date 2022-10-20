
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;


class RoughStrings
{
  public:
  int minRoughness(string s, int n){
      int res =  INT_MAX;
      int count[26];
      for (int i = 0; i < 26; i++){
          count[i] = 0;
      }
      for (int i = 0; i < s.length(); i++){
          count[s[i] - 'a']++;
      }

      //no need to set c1 to 0~25 loop, in that case we need to identify at least 2 characters exsist
      for (int i = 0; i <= 50 ; i++){
          for (int j = 0; j <= 50 ; j++){
              int counter = 0;
              for (int k = 0; k < 26 ; k++){
                  // you can only remove letter - c1/i is min, you have to remove all exsist letters
                  // c2/j is max, you need to remove excess letters
                  if(count[k] < i) counter += count[k];
                  if(count[k] > j) counter += count[k] - j;
              }
              if(counter <= n) res = min(res, abs(i-j));
          }
      }
      return res;
  }
};
