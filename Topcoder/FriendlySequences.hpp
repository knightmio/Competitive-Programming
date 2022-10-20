#include <vector>
#include <algorithm>
#include <set>
using namespace std;


class FriendlySequences
{
  public:
  set<int> convert(int i){
      set<int> s;
      while(i>0){
          s.insert(i%10);
          i = i/10;
      }
      return s;
  }

  int combination(int i){
      int x = 0;
      int sum = 0;
      while(i>x){
          sum += (i-x);
          x++;
      }
      return sum;
  }

  int count(vector<int> array)
  {
    // your code for the problem
    int res = 0;
    int index = 0;
    int length = 0;
    if(array.size() < 2) return res;
    while (index < array.size()-1){
        set<int> a = convert(array.at(index));
        set<int> b = convert(array.at(index+1));
        if(a == b){
            index++;
            length++;
        }else{
            res += combination(length);
            index++;
            length = 0;
        }
    }
    if(length > 0) res += combination(length);
    return res;  // return your result
  }
};
