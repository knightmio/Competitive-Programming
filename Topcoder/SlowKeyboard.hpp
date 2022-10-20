#include <string>
#include <algorithm>
using namespace std;


class SlowKeyboard
{
  public:
  int	enterTime(string time)
  {
    // your code for the problem
    string temp = "";
    temp += time[0];
    temp += time[1];
    int min = stoi(temp);
    temp = "";
    temp += time[3];
    temp += time[4];
    int sec = stoi(temp);

    int res = 4;
    bool end = false;
    while(!end){
        int new_sec = (sec+res) % 60;
        int new_min = (min + (sec+res)/60) % 60;
        string second = to_string(new_sec);
        string minute = to_string(new_min);
        if(new_sec < 10) second = '0' + second;
        if(new_min < 10) minute = '0' + minute;
        int sum  = 4;
        if(minute[0] != minute[1]) sum+=2;
        if(second[0] != minute[1]) sum+=2;
        if(second[0] != second[1]) sum+=2;
        if(sum <= res){
            end = true;
        }else{
            res++;
        }

    }

    return res;  // return your result
  }
};
