#include <vector>
#include <algorithm>
using namespace std;


class SumOfPower
{
  public:
int	findSum(vector	<int>	array)
  {
    // your code for the problem
    int res = 0;
    for(int i = 0; i < array.size(); i++){
        for(int j = i; j < array.size(); j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += array.at(k);
            }
            res += sum;
        }
    }

    return res;  // return your result
  }
};
