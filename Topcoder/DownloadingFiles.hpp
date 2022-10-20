#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


class DownloadingFiles
{
  public:
  double actualTime(vector<string> tasks)
  {
    // your code for the problem
    double bandwidth = 0;
    double sum = 0;
    string speed;
    string t;
    bool temp = true;
    for (int i = 0; i < tasks.size(); i++){
      speed = "";
      t = "";
      temp = true;
      for (int j = 0; j < tasks.at(i).length(); j++){
        if(tasks.at(i)[j] == ' '){
          temp = false;
        }else if(temp){
          speed += tasks.at(i)[j];
        }else{
          t += tasks.at(i)[j];
        }
      }
      bandwidth += stod(speed);
      sum += stod(speed) * stod(t);
    }
    return sum / bandwidth;  // return your result
  }
};
