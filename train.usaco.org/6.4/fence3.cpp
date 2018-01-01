/*
PROG: fence3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MX[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int MY[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};


struct point {
    double x, y;
};

struct line {
    point a, b;
};


int n;
line seg[160];

double get_one_seg(double x, double y, int t) {
    double x1 = seg[t].a.x, x2 = seg[t].b.x;
    double y1 = seg[t].a.y, y2 = seg[t].b.y;
    
    double d1 = sqrt(pow(x1-x, 2) + pow(y1-y, 2));
    double d2 = sqrt(pow(x2-x, 2) + pow(y2-y, 2));
    
    double dot1 = (x-x1)*(x2-x1) + (y-y1)*(y2-y1);
    double dot2 = (x-x2)*(x1-x2) + (y-y2)*(y1-y2);
    
    if (dot1 <= 0 || dot2 <= 0) {
        return min(d1, d2);
    } else {
        double a = y2 - y1, b = x1 - x2, c = -x1 * (y2 - y1) + y1 * (x2 - x1);
        return abs(a * x + b * y + c) / sqrt(a * a + b * b);
    }
}


double get(double a, double b) {
    double ans = 0;
    for (int i = 0; i < n; ++i) ans += get_one_seg(a, b, i);
    return ans;
}

int main() {
    freopen("fence3.in", "r", stdin);
    freopen("fence3.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
     cin >> seg[i].a.x >> seg[i].a.y >> seg[i].b.x >> seg[i].b.y;
     
    double r = 50, a = 50, b = 50;
    
    while (r > 0.001) {
        double aa, bb, dist = 1e10;
        
        for (int k = 0; k < 9; ++k) {
            double at = a + MX[k] * r;
            double bt = b + MY[k] * r;
            double dt = get(at, bt);
            
            if (dt < dist) {
                aa = at;
                bb = bt;
                dist = dt;
            }
        }
        
        a = aa, b = bb, r /= 2;
    }
    
    printf("%.1lf %.1lf %.1lf\n", a, b, get(a, b));
    
    return 0;
}
