// The linkedlist class is from https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/
#include <iostream>
#include <string>

#include <algorithm>

using namespace std;
int i = -1;

void dfs(string numbers, int sum,int num,int carry,int cur_sum)
{
    if(numbers.length() == 1) // boundary
      {
          if(sum == cur_sum+carry+(numbers[0] - '0')){ //update global variable min
                if(i == -1) i = num;
                if(i>num) i = num;
          }
       }else{
           cout<< "current input is "<<numbers <<" " << sum <<" " << num <<" " <<carry <<" " <<cur_sum <<"\n";

 string temp = numbers;
 dfs(temp.erase(0,1),sum,num+1,0,cur_sum+(numbers[0] - '0')+carry);//with plus sign
 temp = numbers;
 dfs(temp.erase(0,1),sum,num,(numbers[0] - '0'+carry)*10,cur_sum);//no with
       }
 }

int main()
{
    string a= "0123456789";
    dfs(a,45,0,0,0);

    cout << i;

    return 0;
}