#include <vector>
#include <algorithm>
using namespace std;


class BootsExchange
{
  public:
int	leastAmount(vector	<int>	left, vector	<int>	right)
  {
    // your code for the problem
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for(int i = 0; i < left.size(); i++){
        for(int j = 0; j < right.size(); j++){
            if(left.at(i) == right.at(j)){
                right.erase(right.begin() + j);
                break;
            }
        }
    }

    return right.size();  // return your result
  }
};
