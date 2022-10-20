#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;


class CubeStickers
{
  public:

  string isPossible(vector<string> sticker){
    int n = sticker.size();
    int res = 2;
    sort(sticker.begin(),sticker.end());
    for (int i = 2; i < n; i++){
      if (sticker.at(i) != sticker.at(i - 1) || sticker.at(i) != sticker.at(i - 2)){
          res++;
      }
    }
    if (res >= 6) return "YES";
    return "NO";
  }
};
