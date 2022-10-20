#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class RockStar
{
  public:
  int getNumSongs(int ff, int fs, int sf, int ss)
  {
    // your code for the problem
    int res = 0;
    if(ff+fs > 0){
        res += ff;
        if(fs > 0) res += ss;
        res = res + fs +sf - (max(fs,sf) - min(fs,sf));
        if(fs > sf) res++;
    }else{
        res += ss;
        if(sf > 0) res++;
    }

    return res;
  }
};
