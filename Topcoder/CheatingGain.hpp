#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class CheatingGain
{
  public:
  int fakeH(vector <int> currentC, int budget, int fakeCost)
  {
    // your code for the problem
    int num = budget/ fakeCost;
    //cout << "num of +1 " << num;
    sort(currentC.begin(),currentC.end());
    int index = 0;
    for(int i = 1; i < currentC.size(); i++){
      if(currentC.at(currentC.size() - i) >= i) index = i;
    }
    while (num > 0){
      for(int i = index+1; i > 0; i--){
        if(currentC.at(currentC.size() - i) < index+1){
          num = num + (currentC.at(currentC.size() - i) -(index+1));
          currentC.at(currentC.size() - i) = index+1;
        }
      }
      for (int i = 0; i <currentC.size(); i++){
        //cout << currentC.at(i) << "  ";
      }
      //cout << num << "\n";
      if (num >= 0) index++;
      if (index == currentC.size()) break;
    }

    return index;
  }
};
