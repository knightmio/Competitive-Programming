using namespace std;

class ChristmasTree
{
  public:
  // surprise there is no inbuilt factorial function
  int f(int i){
    return i < 2 ? 1 :  i * f(i-1);
  }

  long decorationWays(int N, int red, int green, int blue)
  {
    // your code for the problem
    long res = 0;
    //base case
    if(N == 1){
        if (red >= 1) res++;
        if (green >= 1) res++;
        if (blue >= 1) res++;
    }else{
        // 3 cases: use one type 2 types and 3 types
        if(red >= N){
            res += decorationWays(N-1, red - N, green, blue);
        }

        if(blue >= N){
            res += decorationWays(N-1, red, green, blue - N);
        }

        if(green >= N){
            res += decorationWays(N-1, red, green - N, blue);
        }

        //2 types
        if(N % 2 == 0){
            if(red >= N/2 && green >= N/2){
                res += decorationWays(N-1, red - N/2, green - N/2, blue) *f(N)/(f(N/2) * f(N/2));
            }

            if(red >= N/2 && blue >= N/2){
                res += decorationWays(N-1, red - N/2, green, blue - N/2) *f(N)/(f(N/2) * f(N/2));
            }

            if(blue >= N/2 && green >= N/2){
                res += decorationWays(N-1, red, green - N/2, blue - N/2) *f(N)/(f(N/2) * f(N/2));
            }
        }

        //3 types
        if(N % 3 == 0){
            if(red >= N/3 && green >= N/3 && blue >= N/3){
                res += decorationWays(N-1, red - N/3, green - N/3, blue - N/3) *f(N)/(f(N/3) * f(2*N/3)) * f(N - N/3)/(f(N/3) * f(N/3));
            }
        }
    }

    return res;  // return your result
  }
};
