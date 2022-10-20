Question 1 : FillBox
Greedy + recursion?
The size of the array means the max size of box the cube we can fill, so we always try to fill the max cube if possible
for example, test case 4 4 8 {10,10,1}
an array size of 3 means the maximum cube we can fill is 2^(3-1) = 4
then we compare the length,width, height with cube, 4 4 8 >= 4 so we can fill the cube in
the rest part of the box is (length * width - 2^(3-1) *height) / (length - 2^(3-1) * 2^(3-1) *height) / (2^(3-1) * 2^(3-1) *height - 2^(3-1))
do the recursion for these 3 rest part with the modified array(minus the corresponding index)
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;


class FillBox
{
  public:
  int res = 0;
  vector<int> cube;

  void helper(int length, int width, int height, vector<int> cubes){
    int size = cubes.size();
    for(int i = size - 1; i >= 0; i--){
      int side = pow(2,i);
      if(length >= side && width >= side && height >= side && cubes.at(i) > 0){
          res++;
          cube.at(i)--;
          //cout << "a box of " << side<< "test    test    " << length<<"  " << width - side<<"  " << height<< "\n";
          helper(length, width - side, height, cube);
          helper(length - side, side, height, cube);
          helper(side, side, height-side, cube);
          break;
      }
    }
  }

  int minCubes(int length, int width, int height, vector<int> cubes){
    res = 0;
    while (!cube.empty()){
      cube.pop_back();
    }
    for (int i = 0; i < cubes.size(); i++){
      cube.push_back(cubes.at(i));
    }
    helper(length, width, height, cube);
    return res;
  }
};
