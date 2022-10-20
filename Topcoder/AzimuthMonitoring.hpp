#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


class AzimuthMonitoring
{
  public:
  int getAzimuth(vector<string> instructions)
  {
    // your code for the problem
    int res = 0;
    string temp,num;
    int len = instructions.size();
    for (int i = 0; i < len; i++){
      temp = instructions.at(i);
      if (temp.size() == 4){
        if(temp[0] == 'L') res -= 90;
        if(temp[0] == 'H') i = len;
      }else if (temp.size() == 5){
        res += 90;
      }else if (temp[0] == 'T'){
        res += 180;
      }else if (temp[0] == 'L'){
        for(int j = 5; j < temp.size(); j++){
          num += temp[j];
        }
        res -= stoi(num);
        num = "";
      }else if (temp[0] == 'R'){
        for(int j = 6; j < temp.size(); j++){
          num += temp[j];
        }
        res += stoi(num);
        num = "";
      }
    }

    while (res < 0) res += 360;
    res = res % 360;
    return res;  // return your result
  }
};
