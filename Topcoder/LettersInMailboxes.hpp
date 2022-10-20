#include <string>
#include <cstring>
#include <vector>

#include <algorithm>
#include <math.h>
using namespace std;


class LettersInMailboxes
{
  public:
  long maxTurns(long N, long K)
  {
    // your code for the problem
    if ((N - K) == 1) return 1;
    if ((N - K) == 0) return 0;
    if (K == 1) return N-K;
    long temp = K;
    long count = 0;
    while(temp != 0){
        temp = temp/2;
        count++;
    }
    if (N%K == 0)count--;
    if ((N%K + K) < pow(2,count))count--;

    count += N/K-1;
    return count;
  }
};
