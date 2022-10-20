#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


class TwiceString
{
  public:
  string getShortest(string s)
  {
    // your code for the problem
    string temp;
    string temp2;
    for (int i = 1; i < s.length(); i++){
        temp = s;
        temp = temp.erase(s.length() - i,i);
        temp2 = s;
        temp2 = temp2.erase(0,i);
        if (temp == temp2) break;
    }
    string res = s;
    if(temp == temp2)res.erase(res.length()-temp.length(), temp.length());
    res = res + s;
    return res;
  }
};
