#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;
#define FOR(a) for(int i=0;i<=a;i++)
class NiceOrUgly
{
  public:
  vector<string> save;
  bool a;
  bool b;

  bool isVowel(char a){
      if (a == 'A'|| a == 'E'||  a == 'I'||  a == 'O'||  a == 'U')return true;
      return false;
  }

  bool isUgly(string s){
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '0'){
        count1++;
        count2 = 0;
      }else if(s[i] == '?'){
        if(count2 == 0){
          if(count1 == 2)count2++;
          count1 =0;
        }else{
          if(count2 == 4)count1++;
          count2 =0;
        }
      }else{
        count2++;
        count1 = 0;
      }
      if(count1 >= 3) return true;
      if(count2 >= 5) return true;
    }
    return false;
  }

  void question(string s){
    if(s.length()>2){
      for(int i = 0; i < s.length()-2; i++){
        if((s[i] == '0' || s[i] == '?') && (s[i+1] == '0' || s[i+1] == '?') && (s[i+2] == '0' || s[i+2] == '?')) b = true;
      }
    }

    if(s.length()>4){
      for(int i = 0; i < s.length()-4; i++){
        if((s[i] == '1' || s[i] == '?') && (s[i+1] == '1' || s[i+1] == '?') && (s[i+2] == '1' || s[i+2] == '?')
        && (s[i+3] == '1' || s[i+3] == '?')  && (s[i+4] == '1' || s[i+4] == '?') ) b = true;
      }
    }
  }

  string describe(string s){
      b = false;
      string temp = "";
      for(int i = 0; i < s.length(); i++){
          if(s[i] == '?'){
              temp += '?';
          }else if(isVowel(s[i])){
              temp += '0';
          }else{
              temp += '1';
          }
      }
      if(isUgly(temp)) return "UGLY";
      question(temp);
      if(b) return "42";
      return "NICE";
  }
};
