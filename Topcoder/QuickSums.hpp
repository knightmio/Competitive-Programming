#include <string>
#include <cstring>
using namespace std;


class QuickSums
{
  public:
  int i = -1;

  void dfs(string numbers, int sum,int num,int carry,int cur_sum)
  {
    if(numbers.length() == 1) // boundary
        {
        if(sum == cur_sum+carry+(numbers[0] - '0')){ //update global variable min
            if(i == -1) i = num;
            if(i>num) i = num;
        }
    }else{
        string temp = numbers;
        dfs(temp.erase(0,1),sum,num+1,0,cur_sum+(numbers[0] - '0')+carry);//with plus sign
        temp = numbers;
        dfs(temp.erase(0,1),sum,num,(numbers[0] - '0'+carry)*10,cur_sum);//no with
    }
  }


  int minSums(string numbers, int sum)
  {
    // your code for the problem
    i = -1;
    dfs(numbers,sum,0,0,0);
    return i;
  }
};
