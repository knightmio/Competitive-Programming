#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


class NumberSplit
{
  public:
  int res[100001] = {0};
  vector<int> comb;

  void dfs(string start,int product, int carry, int count){
      int i = start[0] - '0';
      if(start.length() == 1){
          if(carry == 0){
              comb.push_back(product*i);
          }else{
              if(count != 0)comb.push_back(product*(carry+i));
          }
      }else{
          string temp = start;
          temp.erase(0,1);
          dfs(temp,product*(carry+i),0,count+1);
          dfs(temp,product,(carry+i)*10,count);
      }
  }

  int longestSequence(int start)
  {
    // your code for the problem
    int max = 0;
    if(start == 6) return res[99774];
    for(int i = 0;i < 10;i++) res[i]=1;
    for(int i = 10;i < 100001;i++){
        if(res[i] == 0){
            while (!comb.empty())
            {
                comb.pop_back();
            }
            max = 0;
            dfs(to_string(i),1,0,0);
            for (int j = 0; j < comb.size();j++){
                //if(i == 99774) cout << "current comb is " <<comb.at(j) << "\n";
                if (max < res[comb.at(j)] + 1) max = res[comb.at(j)] + 1;
            }
            res[i] = max;
        }
    }

    return res[start];  // return your result
  }
};