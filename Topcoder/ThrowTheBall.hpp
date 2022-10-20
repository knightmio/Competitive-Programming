#include <numeric>
using namespace std;


class ThrowTheBall
{
  public:
  int timesThrown(int N, int M, int L)
  {
    // your code for the problem
    int times = lcm(N,L) / L;
    return (M - 1) * times;  // return your result
  }
};
