#include <vector>
#include <algorithm>
using namespace std;


class ElevatorLimit
{
  public:
  vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit)
  {
    // your code for the problem
    int min = 0;
    int max = physicalLimit;
    int cur_min = 0;
    int cur_max = physicalLimit;
    vector<int> res;

    for (int i = 0; i < enter.size(); i++){
        if (exit.at(i) > physicalLimit || enter.at(i) > physicalLimit) return res;
        cur_min -= exit.at(i);
        if(cur_min < 0){
            min += (-cur_min);
            cur_min = 0;
        }
        cur_min += enter.at(i);

        //max
        cur_max = cur_max - exit.at(i) + enter.at(i);
        if(cur_max > physicalLimit){
            max = max - (cur_max - physicalLimit);
            cur_max = physicalLimit;
        }

        if(max>physicalLimit || min>physicalLimit) return res;
    }
    if(min > max) return res;
    res.push_back(min);
    res.push_back(max);
    return res;
  }
};
