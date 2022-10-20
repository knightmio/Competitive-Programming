#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <sstream>

using namespace std;


class BlockEnemy
{
  public:
  int occupied[50];
  struct node{
      int x,y,z;
      bool operator <(const node &a)const{
          return z > a.z;
      }
  }a[50];

  void helper(int index, int node){

    for(int i = 0 ; i <= index; i++){
      int x = a[i].x;
      int y = a[i].y;
      //if (node == 16) cout << x << "   ???    " << y << "\n";
      if (x == node && !occupied[y]){
        //cout << "change index " << y << " to 1\n";
        occupied[y] = 1;
        if(i == index) helper(index-1,y);
        if(i != index) helper(index,y);

      }else if (y == node && !occupied[x]){
        occupied[x] = 1;
        //cout << "change index " << x << " to 1\n";
                if(i == index) helper(index-1,x);
        if(i != index) helper(index,x);
      }
    }
  }

  int minEffort(int N, vector<string> roads, vector<int> occupiedTowns){
      for (int i = 0; i < N; i++){
        occupied[i] = 0;
      }
      int res = 0;
      for (int i = 0; i < 50; i++){
          a[i].x = 0;
          a[i].y = 0;
          a[i].z = 0;
      }

      for (int i = 0; i < roads.size(); i++){
          string temp = roads.at(i);
          int count = 0;
          string num;
          stringstream ss;
          ss.str(temp);
          while(ss >> num){
              if(count == 0){

                  a[i].x = stoi(num);
                  count++;
              }else if(count == 1){
                  a[i].y = stoi(num);
                  count++;
              }else if(count == 2){
                  a[i].z = stoi(num);
                  res += stoi(num);
                  count++;
              }
          }
      }
      //
      sort(a,a+N);
      for (int i = 0; i < N; i++){
          occupied[i] = 0;
      }
      for (int i = 0; i < occupiedTowns.size(); i++){
          occupied[occupiedTowns.at(i)] = 1;
      }
      //for (int i = 0; i < N; i++){
          //cout << occupied[i] << "\n";
      //}
      for (int i = 0; i < roads.size(); i++){
          int x = a[i].x;
          int y = a[i].y;
          //cout << x << "  " << y << "\n";
          if(!(occupied[x] && occupied[y])){
              //cout << res << "\n";
              //cout <<a[i].x << "  " << a[i].y << "\n";
              res -= a[i].z;
              if(occupied[x]){
                //cout << y<< "  ???\n";
                //occupied[y] = 1;
                helper(i,x);
              }
              else if(occupied[a[i].y]){
                //cout << x  << "  ???\n";
                //occupied[x] = 1;
                helper(i,y);
              }
              //for (int i = 0; i < N; i++){
        //cout << occupied[i] << " ";
      //}
      //cout << "\n";
          }
      }
      return res;
  }
};
