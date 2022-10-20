#include <string>
#include <bits/stdc++.h>
using namespace std;


class StreetParking
{
  public:
  int freeParks(string street)
  {
    // your code for the problem
    set<int> s;
    for (int i = 0; i < street.length(); i++){
      if (street[i] == 'D'){
        s.insert(i);
      }else if (street[i] == 'B'){
        s.insert(i);
        if(i>0) s.insert(i-1);
        if(i>1) s.insert(i-2);
      }else if (street[i] == 'S'){
        s.insert(i);
        if(i>0) s.insert(i-1);
        if(i<street.length() - 1) s.insert(i+1);
      }
    }

    return street.length() - s.size();  // return your result
  }
};
