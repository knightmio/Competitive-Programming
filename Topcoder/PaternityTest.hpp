#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;


class PaternityTest
{
  public:
    vector<int> possibleFathers(string child, string mother, vector<string> men)
  {
    // your code for the problem
    vector<int> res;
    set<int> total;
    set<int> mom;
    set<int> father;
    for (int i=0; i < mother.length();i++){
        if (mother[i] == child[i]){
            mom.insert(i);
        }
        total.insert(i);
    }

    for (int i=0; i < men.size();i++){
        father.clear();
        string temp = men.at(i);
        for (int i=0; i < mother.length();i++){
            if (temp[i] == child[i]){
                father.insert(i);
            }
        }
        if(father.size() >= mother.length()/2){
            set<int> test(mom);
            test.insert(father.begin(), father.end());
            if(test == total) res.push_back(i);
        }
    }

    return res;  // return your result
  }
};
