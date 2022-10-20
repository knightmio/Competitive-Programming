#include <vector>
#include <algorithm>
using namespace std;


class FibonacciDiv2
{
  public:
  int find(int N)
  {
    // your code for the problem
    int count = 1;
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    while ((fib.at(count-1) + fib.at(count)) < 1000000 ){
        fib.push_back(fib.at(count-1) + fib.at(count));
        count++;
    }
    fib.push_back(N);
    sort (fib.begin(), fib.end());
    int index = 0;
    while (index <= count+1){
        if(fib.at(index) != N){
            index++;
        }else{
            break;
        }
    }
    if(index == 0) return 0;
    if(index == count+1) return fib.at(index) - fib.at(index-1);
    return min(fib.at(index) - fib.at(index-1), fib.at(index+1) - fib.at(index));  // return your result
  }
};
