#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class TomekPhone
{
  public:
  int res = 0;

  void helper(vector<int> frequencies, vector<int> keySizes, int index){
    vector<int> temp = frequencies;
    vector<int> temp2 = keySizes;
    sort(temp.rbegin(), temp.rend());
    sort(temp2.rbegin(), temp2.rend());
    if(temp.at(0) != 0){
      int count = 0;
      for (int i =0; i < keySizes.size(); i++){
        if (i < temp.size()){
          if(temp2.at(i) != 0){
            res += index * temp.at(i);
            temp.at(i) = 0;
            temp2.at(i) = temp2.at(i) - 1;
            count++;
          }
        }
      }
      helper(temp, temp2, index+1);
    }
  }

  int minKeystrokes(vector<int> frequencies, vector<int> keySizes)
  {
    // your code for the problem
    res = 0;
    int spaces = 0;
    for (int i =0; i < keySizes.size(); i++){
        spaces += keySizes.at(i);
    }
    if (spaces < frequencies.size()) return -1;
    helper(frequencies, keySizes,1);
    return res;
  }
};
