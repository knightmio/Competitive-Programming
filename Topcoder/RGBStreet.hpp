#include <string>
#include <cstring>
#include <vector>
using namespace std;


class RGBStreet
{
  public:
  int i = -1;
  int memo[20][3];
  void dfs(vector<string> v,int sum, int color)
  {
    //cout<< "we have " <<v.size() << " houses left, this one we chose color " << color << "current sum is " << sum << " current max is " << i <<  "\n";
    string temp = v.at(0);
    int r = -1, g = -1, b = -1;
    string section = "";
    for(int i = 0; i< temp.length();i++){
        if(temp[i] != ' '){
            section += temp[i];
        }else{
            if(r == -1){
                r = stoi(section);
                section = "";
            }else{
                g = stoi(section);
                section = "";
            }
        }
    }
    b = stoi(section);

    if(v.size() == 1) // boundary
    {
        switch(color){
            case 1:{
                if(i == -1) i = sum+r;
                if(i>sum+r) i = sum+r;
                if(memo[v.size()-1][0] == 0) memo[v.size()-1][0] = r;
                break;
            }

            case 2:{
                if(i == -1) i = sum+g;
                if(i>sum+g) i = sum+g;
                if(memo[v.size()-1][1] == 0) memo[v.size()-1][1] = g;
                break;
            }

            case 3:{
                if(i == -1) i = sum+b;
                if(i>sum+b) i = sum+b;
                if(memo[v.size()-1][2] == 0) memo[v.size()-1][2] = b;
                break;
            }
        }
    }else{
        vector<string> next = v;
        next.erase(next.begin());

        switch(color){
        case 1:{
            if(memo[v.size()-2][1] != 0 && memo[v.size()-2][2] != 0){
                int minium = min(memo[v.size()-2][1],memo[v.size()-2][2]);
                if(i>sum+r+ minium) i = sum+r+ minium;
                memo[v.size()-1][color-1] = r + minium;
                //cout << "we update memo "<< v.size()-1 <<" " << color -1 << " with min "<<minium << " plus " <<r <<" to get " << r + minium<<"\n";
                break;
            }else{
                next = v;
                next.erase(next.begin());
                dfs(next, sum+r, 2);
                next = v;
                next.erase(next.begin());
                dfs(next, sum+r, 3);
                break;
            }
        }

        case 2:{
            if(memo[v.size()-2][0] != 0 && memo[v.size()-2][2] != 0){
                int minium = min(memo[v.size()-2][0],memo[v.size()-2][2]);
                if(i>sum+g+ minium) i = sum+g+ minium;
                memo[v.size()-1][color-1] = g + minium;
                break;
                //cout << "we update memo "<< v.size()-1 <<" " << color -1 << " with min "<<minium << " plus " <<g <<" to get " << g + minium<<"\n";
            }else{
                next = v;
                next.erase(next.begin());
                dfs(next, sum+g, 1);
                next = v;
                next.erase(next.begin());
                dfs(next, sum+g, 3);
                break;
            }
        }

        case 3:{
            if(memo[v.size()-2][1] != 0 && memo[v.size()-2][0] != 0){
                int minium = min(memo[v.size()-2][1],memo[v.size()-2][0]);
                if(i>sum+b+ minium) i = sum+b+ minium;
                memo[v.size()-1][color-1] = b + minium;
                break;
                //cout << "we update memo "<< v.size()-1 <<" " << color -1 << " with min "<<minium << " plus " <<b <<" to get " << b + minium<<"\n";
            }else{
                next = v;
                next.erase(next.begin());
                dfs(next, sum+b, 1);
                next = v;
                next.erase(next.begin());
                dfs(next, sum+b, 2);
                break;
            }
        }
        }
    }
  }

  int estimateCost(vector<string> houses)
  {
    // your code for the problem
    i = -1;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 3; j++){
            memo[i][j] = 0;
        }
    }
    dfs(houses,0,1);
    dfs(houses,0,2);
    dfs(houses,0,3);
    return i;
  }
};