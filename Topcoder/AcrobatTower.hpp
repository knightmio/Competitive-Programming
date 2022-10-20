#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;


class AcrobatTower
{
  public:
  int capacity;
  int totalWeight;
  vector<int> index;


  void helper(vector<int> weights, vector<int> strengths){
      int bottom;
      int top;
      if(index.empty()){
          int max_cap = -INT_MAX;
          int weight = 0;
          for(int i = 0; i < weights.size(); i++){
              if(strengths[i] - weights[i] > max_cap){
                  max_cap = strengths[i] - weights[i];
                  weight = weights[i];
                  bottom = i;
              }else if(strengths[i] - weights[i] == max_cap){
                  if(weight < weights[i]) weight = weights[i];
                  bottom = i;
              }
          }
          index.push_back(bottom);
          capacity = strengths[bottom] - weights[bottom];
      }
      for(int i = 0; i < weights.size(); i++){
          if(i != bottom && capacity >= weights[i]){
              index.push_back(i);
              top = i;
              totalWeight += weights[i];
              i = INT_MAX;
          }
      }

      for(int i = 0; i < weights.size(); i++){
          if(i != bottom && i != top){
              int sum = totalWeight;
              int cap = capacity;
              int insert = -1;
              for(int j = 0; j < index.size(); j++){
                  if(j != 0){
                      sum -= weights[index[j]];
                      cap = strengths[index[j]] - weights[index[j]];
                  }
                  //cout << "sum is " << sum << " cap is "<< cap <<"\n";
                  if(cap < sum + weights[i]){
                      j = INT_MAX;
                  }else if(strengths[i] - weights[i] >= sum){
                      insert = 1+j;
                      if(weights[i] == weights[index[j]]) j = INT_MAX;
                  }
              }
              if(insert != -1){
                vector <int>::iterator pos = index.begin() +insert;
                index.insert(pos, i);
                //cout << "push to index " << i << "\n";
                totalWeight += weights[i];
              }
          }
      }
  }

  int maximumHeight(vector<int> weights, vector<int> strengths){
      capacity = -1;
      totalWeight = 0;
      while(!index.empty()){
          index.pop_back();
      }

      vector<int> newWeight(weights);
      vector<int> newStrength;
      sort(newWeight.begin(), newWeight.end());
      for (int i= 0; i < newWeight.size(); i++){
          int temp = newWeight[i];
          vector <int>::iterator pos = find(weights.begin(), weights.end(), temp);
          temp = pos - weights.begin();
          newStrength.push_back(strengths[temp]);
          weights.erase(weights.begin()+temp);
          strengths.erase(strengths.begin()+temp);
      }
      int start = 0;
      int length = 0;
      for (int i = 0; i < newWeight.size()-1; i++){
          if(newWeight[i] != newWeight[i+1]){
              sort(newStrength.begin()+start, newStrength.begin()+start+length+1);
              start = i+1;
              length = 0;
          }else{
              length++;
          }
      }
      for (int i = 0; i < newStrength.size(); i++){
          //cout << newStrength[i] << "  ";
      }
      //cout << "\n";
      helper(newWeight,newStrength);
      for (int i = 0; i < index.size(); i++){
          //cout << index[i] << "  ";
      }

      return index.size();
  }
};
