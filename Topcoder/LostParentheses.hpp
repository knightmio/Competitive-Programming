#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
class LostParentheses
{
  public:
  int res;

  void helper(string e,bool minus){
    string temp = e;
    string num = "";
    char op;
    int count = 0;
    for(int i = 0; i <e.length(); i++){
        if(e[i] != '+' && e[i] != '-'){
            num += e[i];
        }else{
            count = i;
            op = e[i];
            i = e.length();
        }
    }
    temp.erase(0,count+1);
    cout << num << "  " << temp << "\n";
    if(!minus) res += stoi(num);
    if(minus) res -= stoi(num);
    if(count != 0){
        bool sign = minus;
        if(!sign) sign =(op=='-');
        //cout << "next call is " << temp << "  "<< sign <<"with res " << res << "\n";
        helper(temp, sign);
    }
  }

  int minResult(string e)
  {
    // your code for the problem
    res = 0;
    helper(e, false);
    return res;
  }
};
