#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class WordGame
{
  public:
  int bestScore(string S)
  {
    // your code for the problem
    int alphabet[26];
    for (int i = 0; i < 26; i++){
      alphabet[i] = 0;
    }

    for (int i = 0; i < S.length(); i++){
        //cout << S[i] - 'A' << " ";
      alphabet[S[i] - 'A'] ++;
    }
    int n = sizeof(alphabet) / sizeof(alphabet[0]);
    sort(alphabet, alphabet + n);

        alphabet[25] += alphabet[24];
        alphabet[24] = 0;
    int res = 0;
    for (int i = 0; i < 26; i++){
      res += alphabet[i]*alphabet[i];
    }

    return res;
  }
};
