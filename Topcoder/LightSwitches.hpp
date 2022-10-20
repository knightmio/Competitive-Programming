#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;


class LightSwitches
{
  public:
  long countPossibleConfigurations(vector<string> switches){
      int res = 0;
      bool on[50][50];
      bool valid[50];
      for(int i = 0; i < 50; i++){
          valid[i] = false;
          for(int j = 0; j < 50; j++){
              on[i][j] = 0;

          }
      }
      for(int i = 0; i < switches.size(); i++){
          valid[i] = true;
          for(int j = 0; j < switches.at(0).length(); j++){
              on[i][j] = (switches.at(i)[j] == 'Y');
          }
      }

      for(int i = 0; i < switches.at(0).length(); i++){
          for(int j = 0; j < switches.size(); j++){
              if(on[j][i] && valid[j]){
                  cout << j << "  " << i << "\n";
                  res++;
                  valid[j] = false;
                  for(int k = j+1; k < switches.size(); k++){
                      if(on[k][i] == 1 && valid[k]){
                          for (int l = i+1; l < switches.at(0).length(); l++){
                              on[k][l] ^= on[j][l];
                          }
                      }
                  }
                  j = INT_MAX;
              }
          }
      }
      return pow(2,res);
  }
};
