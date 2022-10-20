#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define LL long long
#define ll LL
#define vll vector<ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define all(_obj) _obj.begin(), _obj.end()

int main()
{
    double x, y, w, h;
    cin >> x >> y >> w >> h;
    double r, sx, sy, ex, ey;
    cin >> r >> sx >> sy >> ex >> ey;
    double slope = (1.0*ey - sy) / (ex - sx);
    double inverse_slop = -1 / slope;
    if (slope == 0) inverse_slop = 10000000000;
    if (ex == sx) {
        slope = 10000000000;
        inverse_slop = 0;
    }
    function<double(double, double, double, double)> dis = [&](double x, double y, double x2, double y2) -> double {
        return (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
    };
    function<bool(double, double)> verify = [&](double x, double y) -> bool {
        double a = ((y - sy) - (x - sx) * inverse_slop) / (slope - inverse_slop);
        double nx = sx + a;
        double ny = sy + a * slope;


        //cout <<  nx << " " << ny << "\n";
        //超出巡逻范围
        if ((nx > sx && nx > ex) || (nx < sx && nx < ex)) {
            double line1 = dis(nx, ny, x, y) + dis(nx, ny, sx, sy);
            double line2 = dis(nx, ny, x, y) + dis(nx, ny, ex, ey);
            if (min(line1, line2) <= r*r + 1e-4) return true;
        }
        else {
            double line1 = dis(nx, ny, x, y);
            if (line1 <= r*r + 1e-4) return true;
        }
        return false;
    };
    //cout << "\n";
    if (!verify(x, y)) {
        cout << "Safe";
        return 0;
    }
    if (!verify(x+w, y)) {
        cout << "Safe";
        return 0;
    }
    if (!verify(x, y+h)) {
        cout << "Safe";
        return 0;
    }
    if (!verify(x+w, y+h)) {
        cout << "Safe";
        return 0;
    }
    cout << "Oh no!";
    return 0;
}
