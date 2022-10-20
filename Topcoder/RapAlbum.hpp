#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class RapAlbum
{
  public:
  int a[51][51][51][51];
  int countWays(int X, int George, int eli, int mel){
    if(George < 0 || eli < 0 || mel < 0) return 0;
    if(X > (George+ eli+ mel)) return 0;
    if(X == 0){
        if(George == 0 && eli == 0 && mel ==0)return 1;
        return 0;
    }
    if(a[X][George][eli][mel] != 0) return a[X][George][eli][mel];

    int res = 0;
    //cout << "test";
    res += countWays(X-1, George-1, eli, mel);
    res += countWays(X-1, George-1, eli-1, mel);
    res += countWays(X-1, George-1, eli, mel-1);
    res += countWays(X-1, George-1, eli-1, mel-1);
    res += countWays(X-1, George, eli-1, mel);
    res += countWays(X-1, George, eli-1, mel-1);
    res += countWays(X-1, George, eli, mel-1);
    a[X][George][eli][mel] = res;
    //cout << X << "  " << George << "  " << eli << "  " << mel << "  " << res<< "\n";
    return res;
  }
};
