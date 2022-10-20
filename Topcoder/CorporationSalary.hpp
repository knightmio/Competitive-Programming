#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class WordGame
{
  public:
  bool helper(int a[50], bool b[50], int c){
    for(int i =0; i < c; i++){
      if(a[i] != 0 && b[i] == 0) return false;
    }
    return true;
  }

  long totalSalary(vector<string> relations){
    int col[50];
    bool nosub[50];
    for (int i =0; i < 50;i++){
      col[i] = 0;
      nosub[i] = true;
    }
    for (int i = 0; i<relations.size(); i++){
        string temp = relations.at(i);
        for (int j =0 ; j < relations.size();j++){
            if(temp[j] == 'Y'){
              col[j]++;
              //cout <<"row " << i <<" col "<< j <<" \n";
              nosub[i] = false;
            }

        }
    }
    while(!helper(col,nosub,relations.size())){
      for (int i = 0; i<relations.size(); i++){
        if(!nosub[i]){
          string temp = relations.at(i);
          for (int j =0 ; j < relations.size();j++){
            if(temp[j] == 'Y'){
              col[j] += col[i];
            }
          }
          col[i] = 0;
        }
      }
    }
    long res =0;
    for (int i = 0; i<relations.size(); i++){
      if(nosub[i]){
        res += col[i] +1;
      }
    }
    return res;
  }
};
