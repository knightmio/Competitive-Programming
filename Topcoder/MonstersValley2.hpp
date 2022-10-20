#include <vector>
#include <algorithm>
using namespace std;


class MonstersValley2
{
  public:
  int i = 0;

  int dp(int index,long s,int c,vector<int> d,vector<int> p)
  {
    if(index == d.size()) return c;

    if(d.at(index) > s) return dp(index+1, s+d.at(index), c+p.at(index), d, p);

    return min(dp(index+1, s, c, d, p), dp(index+1, s+d.at(index), c+p.at(index), d, p));
  }

  int minimumPrice(vector<int> dread, vector<int> price)
  {
    // your code for the problem

    return dp(0, 0, 0, dread, price);
  }
};
