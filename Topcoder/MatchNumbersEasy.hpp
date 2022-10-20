#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class MatchNumbersEasy
{
  public:
  int min(vector<int> matches){
      int min = matches.at(0);
      int index = 0;
      for(int i = 0; i < matches.size(); i++){
          if (min >= matches.at(i)){
            min = matches.at(i);
            index = i;
          }
      }
      return index;
  }

  string maxNumber(vector<int> matches, int n)
  {
    // your code for the problem
    if(matches.size() == 1) return "0";
    vector<int> temp = matches;
    temp.erase(temp.begin()+0);
    int min1 = min(matches);
    int min2 = min(temp)+1;
    int len = max(n/matches.at(min2),(n-matches.at(min2))/matches.at(min1)+1);
    //cout << min1 << "  " << min2 << "  " << len;
    if(len == 0) return "0";
    string res = "";
    int count = matches.at(min2);
    res += to_string(min2);
    for (int i = 1; i< len;i++){
        res += to_string(min1);
        count += matches.at(min1);
    }
    if (count > n) return "0";

    for (int i = 0; i< len;i++){
        if(count < n){
            for(int j=0; j < matches.size();j++){
                int digit = res[i] - '0';
                if(j > digit && (matches.at(j) - matches.at(digit) + count) <= n){
                    //cout <<res;
                    res[i] = '0' + j;
                    //cout << "  " <<res << " " << count;
                    count = (matches.at(j) - matches.at(digit) + count);
                    //cout << "  " <<res << " " << count;
                }
            }
        }
    }
    return res;
  }
};
