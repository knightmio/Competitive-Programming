#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int oneDigit(int num)
{

    // Comparison operation is faster
    // than division
    // operation. So using following
    // instead of "return num
    // / 10 == 0;"
    return (num >= 0 && num < 10);
}

// A recursive function to find
// out whether num is
// palindrome or not. Initially, dupNum
// contains address of
// a copy of num.
bool isPalUtil(int num, int* dupNum)
{

    // Base case (needed for recursion
    // termination): This
    // statement mainly compares the
    // first digit with the
    // last digit
    if (oneDigit(num))
        return (num == (*dupNum) % 10);

    // This is the key line in this
    // method. Note that all
    // recursive calls have a separate
    // copy of num, but they
    // all share same copy of *dupNum.
    // We divide num while
    // moving up the recursion tree
    if (!isPalUtil(num / 10, dupNum))
        return false;

    // The following statements are
    // executed when we move up
    // the recursion call tree
    *dupNum /= 10;

    // At this point, if num%10 contains
    // i'th digit from
    // beginning, then (*dupNum)%10
    // contains i'th digit
    // from end
    return (num % 10 == (*dupNum) % 10);
}

// The main function that uses
// recursive function
// isPalUtil() to find out whether
// num is palindrome or not
int isPal(int num)
{

    // Check if num is negative,
    // make it positive
    if (num < 0)
        num = -num;

    // Create a separate copy of num,
    // so that modifications
    // made to address dupNum don't
    // change the input number.
    // *dupNum = num
    int* dupNum = new int(num);

    return isPalUtil(num, dupNum);
}

int main()
{
	long long count = 0;
	for (int i = 1; i < 100000000; i++) {
        if (isPal(i)) {
            cout << i << "\n";
            count++;
        }
	}
	cout << count;
	return count;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
