#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class SquareOfDigits
{
  public:
  int getMax(vector<string> data)
  {
    // your code for the problem
    int size = min(data.size(), data[0].length()) - 1;
    int res = 1;
    for (int i = size; i > 0; i--){
      for (int j = 0; j < data[0].length(); j++){
        if((j + i) < data[0].length()){
          for (int k = 0; k < data.size(); k++){
            if((k + i) < data.size()){
              if(data[k].at(j) == data[k+i].at(j) && data[k+i].at(j+i) == data[k].at(j+i) && data[k+i].at(j+i) == data[k].at(j)) return pow(i+1,2);
            }
          }
        }
      }
    }
    return res;  // return your result
  }
};
