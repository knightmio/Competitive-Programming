#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


class HenrysKey
{
  public:
  int howMany(string S)
  {
    // your code for the problem
    int res = 0;
    char temp = ' ';
    for (int i= 0; i < S.length(); i++){
        if(temp != S[i]){
            res++;
        }
        temp = S[i];
    }
    return res;  // return your result
  }
};
