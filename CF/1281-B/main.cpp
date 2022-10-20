#include<iostream>
#include <cstdlib>
using namespace std;
int num;
string a, b;
int main() {
    //AMAZON - x = n-1
    //O > N a = n-2, b = n-1 可以交换O和N x还是n-1
    //Z > N a = n-3, b = n-1 可以交换Z和N x还是n-1
    //A < N 不可以交换A和N x是n-4 = A - 因为A比N小 更有价值?
    //M > A 可以交换

    cin >> num;
    while (num--) {
        cin >> a >> b;
        int n = a.size();
        int x = n, a1 = 0, b1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if(x != n && a[i] > a[x]){
                a1 = i;
                b1 = x;
            }
            if(x == n || a[x] > a[i]) x = i;
        }
        //cout << a1 << "\n" << b1 << endl;
        swap(a[a1], a[b1]);
        if (a < b) {
            cout << a << endl;
        } else {
            cout << "---" << endl;
        }
    }
    //system("pause");
    return 0;
}
