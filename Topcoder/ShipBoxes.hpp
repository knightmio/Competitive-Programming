#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
class ShipBoxes
{
  public:
  int calculate(vector<int> box){
    sort(box.begin(), box.end());
    return box.at(0)*box.at(1)*4+box.at(0)*box.at(2)*2+box.at(1)*box.at(2)*2;
  }

  int bestCost(vector<int> box1, vector<int> box2)
  {
    // your code for the problem
    vector<int> box3;
    // you have to sort the vector in ascending order before next_permutation!!!
    sort(box1.begin(),box1.end());
    sort(box2.begin(),box2.end());
    int minimum = 2147483647;
    int index = -1;
    do {
      do {
        while(!box3.empty()){
          box3.pop_back();
        }
        box3.push_back(max(box1[0],box2[0]));
        box3.push_back(max(box1[1],box2[1]));
        box3.push_back(box1[2]+box2[2]);
        int temp = calculate(box3);
        if (temp < minimum) minimum = temp;
      } while(next_permutation(box2.begin(),box2.end()));
    } while(next_permutation(box1.begin(),box1.end()));
    return minimum;
  }
};
