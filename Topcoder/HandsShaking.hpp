#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class HandsShaking
{
  public:
  bool ini = false;
  long save[26];
  void initialize(){
    save[0] = 1;
    for (int i = 1; i <= 25; i++){
        save[i] = 0;
        for (int j = 0; j < i; j++){
            save[i] += save[j] * save[i - j - 1];
        }
    }
    ini = true;
  }

  long countPerfect(int n){
      if(!ini) initialize();
      return save[n/2];
  }
};
