#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


class BoardPieces
{
  public:
  int countSame(vector<string> board)
  {
    // your code for the problem
    // since we have a input of square we just traverse each row and col at the same time
    int max = 1;
    int count = 1;
    if (board.size() == 1) return 1;
    string row = "";
    char temp = ' ';
    //row
    for (int i = 0; i < board.size(); i++){
        row = board.at(i);
        temp = row[0];
        for (int j = 1; j < board.size(); j++){
            if (temp == row[j]){
                count++;
            }else{
                if(count > max) max = count;
                count = 1;
            }
            temp = row[j];
        }
        if(count > max) max = count;
        count = 1;
    }

    //col
    for (int i = 0; i < board.size(); i++){
        row = board.at(0);
        temp = row[i];
        for (int j = 1; j < board.size(); j++){
            row = board.at(j);
            if (temp == row[i]){
                count++;
            }else{
                if(count > max) max = count;
                count = 1;
            }
            temp = row[i];
        }
        if(count > max) max = count;
        count = 1;
    }
    return max;
  }
};
