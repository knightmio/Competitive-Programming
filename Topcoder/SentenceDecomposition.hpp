#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;


class SentenceDecomposition
{
  public:
  int trans(string sub, vector<string> validWords){
      int res = INT_MAX;
      string s1 = sub;
      sort(s1.begin(), s1.end());
      string s2;
      for (int i = 0; i < validWords.size(); i++){
          s2 = validWords.at(i);
          sort(s2.begin(), s2.end());
          if (s1 == s2){
              int count = 0;
              for(int j = 0; j< sub.length();j++){
                  if(sub[j] != validWords.at(i)[j]) count++;
              }
              if(res > count) res = count;
          }
      }
      if (res == INT_MAX) return -1;
      return res;
  }

  int decompose(string sentence, vector<string> validWords){
      if(sentence.length() == 0) return 0;
      int res = INT_MAX;
      for (int i = 1; i <= sentence.length(); i++){
          string temp = sentence.substr(0, i);
          if(trans(temp, validWords) >= 0){
              string temp2 = sentence.substr(i, sentence.length()-i);
              //cout << "current string is " << sentence << " with next sub " << temp2 <<  "\n";
              int rest = decompose(temp2, validWords);
              if(rest >= 0){
                  res = min(res, rest + trans(temp, validWords));
              }
              if(res == 0) return 0;
          }
      }
      if (res == INT_MAX) return -1;
      return res;
  }
};
