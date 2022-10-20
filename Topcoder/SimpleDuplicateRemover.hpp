#include <vector>
#include <algorithm>
using namespace std;


class SimpleDuplicateRemover
{
  public:
  vector<int> process(vector<int> sequence)
  {
    // your code for the problem
    vector<int> res;
    for(int i = sequence.size()-1; i >= 0;i--){
        if(find(res.begin(), res.end(), sequence.at(i)) == res.end()){
            res.insert(res.begin(), sequence.at(i));
        }
    }
    return res;  // return your result
  }
};
