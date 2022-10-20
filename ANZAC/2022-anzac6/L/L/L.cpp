#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

const int N = 20;
string ans[10];
string sub(string a, string b)
{
	int i, j, flag = 1;
	int tmpa[20], tmpb[20], c[20];
	string ans;
	if (a.size() < b.size() || (a.size() == b.size() && a.compare(b) < 0)) {
		string tmp = a;
		a = b;
		b = tmp;
		flag = 0;
	}
	while (a.length() > b.length())b = '0' + b;
	int len = a.length();
	for (i = 0; i < len; i++) {
		tmpa[i] = a[i] - '0';
		tmpb[i] = b[i] - '0';
	}
	for (i = len - 1; i >= 0; i--) {
		if (tmpa[i] >= tmpb[i])
			c[i] = tmpa[i] - tmpb[i];
		else {
			c[i] = 10 + tmpa[i] - tmpb[i];
			tmpa[i - 1]--;
		}
	}
	for (i = 0; i < len - 1; i++) {
		if (c[i] != 0)
			break;
	}
	for (j = i; j < len; j++)
		ans = ans + (char)(c[j] + '0');
	if (!flag)ans = '-' + ans;
	return ans;
}

bool isPalindrome(string S)
{
	string P = S;
	reverse(P.begin(), P.end());
	if (S == P) {
		return true;
	}
	return false;
}

int main()
{
	string str;
	int cnt = 0;
	cin >> str;
	while (true) {
		if (isPalindrome(str)) {
			if (str.length() != 1 || str[0] != '0') {
				ans[cnt++] = str;
				break;
			}
		}
		int len_str = str.length();
		if (len_str & 1) {
			string temp;
			temp.clear();
			int Left = len_str / 2 - 1;
			int Right = Left + 2;
			while (str[Left] == str[Right])Left--, Right++;
			if (Left == 0 && str[Right] == '0') {
				temp.clear();
				for (int i = 0; i < len_str - 1; i++)
					temp += '9';
				if (str[0] != '1') {
					temp.clear();
					for (int i = 0; i < len_str; i++) {
						temp += (str[0] - 1);
					}
				}
			}
			else {
				temp.clear();
				char op = str[Right];
				int mid = len_str / 2;
				for (int i = 0; i <= mid; i++)
					temp += str[i];
				int pos = mid - 1;
				while (pos != -1) temp += temp[pos--];
				if (str[Left] > str[Right]) {
					temp[Left] = temp[Right] = op;
				}
			}
			ans[cnt++] = temp;
			str = sub(str, temp);
		}
		else {
			string temp;
			int Left, Right;
			Left = len_str / 2 - 1;
			Right = Left + 1;
			while (str[Left] == str[Right])Left--, Right++;
			if (Left == 0 && str[Right] == '0') {
				temp.clear();
				for (int i = 0; i < len_str - 1; i++)
					temp += '9';
				if (str[0] != '1') {
					string test;
					temp.clear();
					for (int i = 0; i < len_str; i++)
						temp += (str[0] - 1);
				}
			}
			else {
				temp.clear();
				char op = str[Right];
				int mid = (len_str / 2) - 1;
				for (int i = 0; i <= mid; i++)
					temp += str[i];
				int pos = mid;
				while (pos != -1)temp += temp[pos--];
				if (str[Left] > str[Right]) 
					temp[Left] = temp[Right] = op;
			}
			ans[cnt++] = temp;
			str = sub(str, temp);
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}