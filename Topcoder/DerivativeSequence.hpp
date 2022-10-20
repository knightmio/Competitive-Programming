#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


class DerivativeSequence
{
  public:
  vector<int> derSeq(vector<int> a, int n)
  {
    // your code for the problem
    // base case
    if(n == 0){
        return a;
    }else{
        int size = a.size();
        vector<int> temp;
        for (int i = 0; i < size - 1; i++){
            temp.push_back(a[i+1] - a[i]);
        }
        return derSeq(temp, n-1);
    }
  }
};
