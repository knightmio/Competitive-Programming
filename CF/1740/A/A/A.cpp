#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    vector<int> primes;
    primes.push_back(2);
    unordered_set<int> s;
    s.insert(2);
    for (int i = 3; i < 500000; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
            s.insert(i);
        }
    }
    int len = primes.size();
	int t;
	cin >> t;
	rep(i, 0, t - 1) { 
		int n;
		cin >> n;
        rep(j, 0, len - 1) {
            if (!s.count(n + primes[j])) {
                cout << primes[j] << "\n";
                break;
            }
        }
	}
}