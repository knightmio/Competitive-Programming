#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class HouseBuilding
{
  public:
  int res = 0;
  vector<int> sum;

  void helper(vector<string> area, int lowest){
    res = 0;
    string temp;
    for (int i = 0; i < area.size(); i++){
      temp = area.at(i);
      for (int j = 0; j < temp.length(); j++){
        int height = temp[j] - '0';
        if (height >= lowest + 1) res += (height - lowest - 1);
        if (height <= lowest) res += (lowest - height);
      }
    }
  }

  int getMinimum(vector<string> area)
  {
    // your code for the problem
    while (!sum.empty())
    {
      sum.pop_back();
    }
    for (int i = 0; i < 9; i++){
      helper(area,i);
      sum.push_back(res);
      cout << "The res for min " << i << " is " << res << "\n";
    }
    sort(sum.begin(), sum.end());
    return sum.at(0);
  }
};
