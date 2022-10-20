#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class CircularLine
{
  public:
  int longestTravel(vector<int> t)
  {
    // your code for the problem
    int total = 0;
    int res = 0;
    int temp = 0;
    int len = t.size();
    for (int i = 0; i < len; i++){
      total += t.at(i);
    }

    for (int i = 0; i < len; i++){
      temp = 0;
      for (int j = i; j < len; j++){
        temp += t.at(j);
        if (temp > res && (total - temp) > res) res = min(temp,(total - temp));
      }
    }

    return res;  // return your result
  }
};