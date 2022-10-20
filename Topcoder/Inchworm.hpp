#include <numeric>
using namespace std;


class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
    // your code for the problem
    int res = branch / lcm(rest,leaf) + 1;
    return res;  // return your result
  }
};
