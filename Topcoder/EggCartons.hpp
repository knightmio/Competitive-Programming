using namespace std;


class EggCartons
{
  public:
  int minCartons(int n)
  {
    // your code for the problem
    if (n % 2 == 1) return -1;
    if (n < 6) return -1;
    int res = n / 8;
    int remain = n % 8;
    if (remain == 0) return res;
    if (n >= (4 - remain/2) * 6){
        return (n - (4 - remain/2) * 6)/8+(4 - remain/2);
    }

    return -1;  // return your result
  }
};
