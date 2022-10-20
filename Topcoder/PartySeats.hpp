#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class PartySeats
{
  public:
  vector<string> seating(vector<string> attendees)
  {
    // your code for the problem
    vector<string> res,boy,girl;
    string temp;
    for (int i = 0; i < attendees.size(); i++){
        temp = attendees.at(i);
        if(temp.find(" boy") != -1){
            temp.resize(temp.size() - 4);
            boy.push_back(temp);
        }

        if(temp.find(" girl") != -1){
            temp.resize(temp.size() - 5);
            girl.push_back(temp);
        }
    }

    if(boy.size() != girl.size()) return res;
    if(boy.size() % 2 == 1) return res;

    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());

    res.push_back("HOST");
    int count = 0;
    for (int j = 0; j < boy.size(); j++){
        if (count == boy.size()){
            res.push_back("HOSTESS");
            count++;
        }

        if (count < boy.size()){
            res.push_back(girl.at(j));
            count++;
            res.push_back(boy.at(j));
            count++;
        }

        if (count > boy.size()){
            res.push_back(boy.at(j));
            res.push_back(girl.at(j));
        }
    }
    return res;  // return your result
  }
};
