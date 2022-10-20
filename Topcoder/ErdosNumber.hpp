#include <vector>
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;


class ErdosNumber
{
  public:
  int getNum(vector<string> author,vector<int> num, string name){
      auto it = find(author.begin(), author.end(), name);
      if (it != author.end()){
        int index = it - author.begin();
        return num.at(index);
      }else {
          return -1;
      }
  }

  bool recorded(vector<string> author, string name){
    for (int i = 0; i < author.size(); i++){
        if(author.at(i) == name) return true;
    }
    return false;
  }

  vector<string> calculateNumbers(vector<string> publications){
    vector<string> author;
    vector<int> num;
    queue<string> index;
    for (int i = 0; i < publications.size(); i++){
        string temp = publications.at(i);
        temp = " " + temp + " ";
        if (temp.find(" ERDOS ") != string::npos) {
            if(!recorded(author,"ERDOS")){
                author.push_back("ERDOS");
                num.push_back(0);
            }
            istringstream ss(temp);
            string name;
            while (ss >> name){
                if(!recorded(author,name)){
                    author.push_back(name);
                    num.push_back(1);
                    index.push(name);
                }
            }
        }
    }

    while(!index.empty()){
          string cur = index.front();
          index.pop();
          for (int i = 0; i < publications.size(); i++){
            string temp = publications.at(i);
            temp = " " + temp + " ";
            if (temp.find(" "+cur + " ") != string::npos) {
                istringstream ss(temp);
                string name;
                while (ss >> name){
                    if(!recorded(author,name)){
                        author.push_back(name);
                        num.push_back(getNum(author, num, cur)+1);
                        index.push(name);
                        //cout << "I am adding " << name << " with number" << getNum(author, num, cur)+1 << "from name " << cur <<"\n";
                    }
                }
            }
          }
    }

    for (int i = 0; i < publications.size(); i++){
        string temp = publications.at(i);
        istringstream ss(temp);
        string name;
        while (ss >> name){
            vector<string>::iterator it;
            it = find(author.begin(), author.end(), name);
            if (it == author.end()) author.push_back(name);
        }
    }

    for(int i = 0; i < num.size(); i++){
        author.at(i) += " ";
        author.at(i) += to_string(num.at(i));
    }
    sort(author.begin(),author.end());
    return author;
  }
};
