#include<iostream>
#include <cstdlib>
using namespace std;
int num;
string a, b;
int main() {
    //AMAZON - x = n-1
    //O > N a = n-2, b = n-1 ���Խ���O��N x����n-1
    //Z > N a = n-3, b = n-1 ���Խ���Z��N x����n-1
    //A < N �����Խ���A��N x��n-4 = A - ��ΪA��NС ���м�ֵ?
    //M > A ���Խ���

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
