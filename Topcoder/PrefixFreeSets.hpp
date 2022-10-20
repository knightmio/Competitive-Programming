#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
#define FOR(a) for(int i=0;i<=a;i++)
class PrefixFreeSets
{
  public:
  struct compare {
    inline bool operator()(const string& first, const string& second) const
    {
        return first.size() > second.size();
    }
  };

  bool prefix(string a, string b){
    size_t found = a.find(b);
    if (found == 0) return true;
    return false;
  }

  int maxElements(vector<string> words)
  {
    // your code for the problem
    // sort the vector from max length to min length;
    compare c;
    sort(words.begin(), words.end(), c);

    vector<string> temp = words;
    vector<string> temp2;
    int count = 0;
    while (!temp.empty()){
        //empty temp2
        while (!temp2.empty()){
            temp2.pop_back();
        }
        //push every word that is not a prefix to temp2
        for(int i = 1; i< temp.size();i++){
            if(!prefix(temp.at(0),temp.at(i))){
                temp2.push_back(temp.at(i));
            }
        }
        count++;
        temp = temp2;
    }
    return count;
  }
};
