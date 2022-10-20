#include <vector>
#include <algorithm>
using namespace std;


class UnsealTheSafe
{
  public:
  long save[30][10] = {0};

  long helper(int N, int i){
      long sum = 0;
      //base case
      if(N == 0){
          return 1;
      }

      if (save[N][i] != 0) return save[N][i];
      switch(i){
        case 0:{
            sum+=helper(N-1, 7);
            break;
        }

        case 1:{
            sum+=helper(N-1, 2);
            sum+=helper(N-1, 4);
            break;
        }

        case 2:{
            sum+=helper(N-1, 1);
            sum+=helper(N-1, 3);
            sum+=helper(N-1, 5);
            break;
        }

        case 3:{
            sum+=helper(N-1, 2);
            sum+=helper(N-1, 6);
            break;
        }

        case 4:{
            sum+=helper(N-1, 1);
            sum+=helper(N-1, 5);
            sum+=helper(N-1, 7);
            break;
        }

        case 5:{
            sum+=helper(N-1, 2);
            sum+=helper(N-1, 4);
            sum+=helper(N-1, 6);
            sum+=helper(N-1, 8);
            break;
        }

        case 6:{
            sum+=helper(N-1, 3);
            sum+=helper(N-1, 5);
            sum+=helper(N-1, 9);
            break;
        }

        case 7:{
            sum+=helper(N-1, 4);
            sum+=helper(N-1, 8);
            sum+=helper(N-1, 0);
            break;
        }

        case 8:{
            sum+=helper(N-1, 5);
            sum+=helper(N-1, 9);
            sum+=helper(N-1, 7);
            break;
        }

        case 9:{
            sum+=helper(N-1, 6);
            sum+=helper(N-1, 8);
            break;
        }
      }
      if (save[N][i] == 0) save[N][i] = sum;
      return sum;
  }

  long countPasswords(int N)
  {
    // your code for the problem
    long sum = 0;
    for(int i = 0; i<10; i++){
        sum += helper(N-1,i);
    }
    return sum;  // return your result
  }
};
