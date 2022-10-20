#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class ColorfulRabbits
{
  public:
  int getMinimum(vector<int> replies)
  {
    // your code for the problem
    set<int> s1;
    int res = 0;
    for(int i = 0; i < replies.size(); i++){
        s1.insert(replies.at(i));
    }

    set<int>:: iterator it;
    for( it = s1.begin(); it!=s1.end(); ++it){
        int ans = *it;
        int count = 0;
        for(int i = 0; i < replies.size(); i++){
            if(ans == replies.at(i)) count++;
        }
        int temp = count/(ans + 1);
        if (temp * (ans + 1) < count) res += (ans + 1)* (temp+1);
        if (temp * (ans + 1) == count) res += (ans + 1)* (temp);
    }

    return res;
  }
};
