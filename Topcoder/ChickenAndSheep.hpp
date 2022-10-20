#include <vector>
#include <algorithm>
using namespace std;


class ChickenAndSheep
{
  public:
  vector<int> howMany(int heads, int legs)
  {
    // your code for the problem
    vector<int> res;
    if (legs > heads * 4) return res;
    if (legs < heads * 2) return res;

    int sheep = (legs - 2 * heads)/2;
    int chicken = heads - sheep;
    if ((sheep * 4 + chicken * 2) == legs){
        res.push_back(chicken);
        res.push_back(sheep);
    }
    return res;
  }
};
