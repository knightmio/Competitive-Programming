
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
class TaliluluCoffee
{
  public:
  int maxTip(vector<int> tips)
  {
    // your code for the problem
    int res = 0;
    sort(tips.begin(), tips.end(), greater<int>());
    for (int i = 0; i < tips.size(); i++){
        if((tips.at(i) - i) > 0) res += (tips.at(i) - i);
    }
    return res;
  }
};
