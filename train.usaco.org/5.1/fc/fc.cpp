/*
ID: neeyant2
PROG: fc
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPSILON = 0.0000001;
const int MAXN = 10010;

struct node {
    double x, y;
};

int n;
node x[MAXN];
vector<int> upper, lower;

// High precision check for zero
int check_zero(double a) {
    if (abs(a) < EPSILON) return 0;
    if (a > 0) return 1; else return -1;
}

double cross_product(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}

double cross(int a, int b, int c) {
    return cross_product(x[b].x - x[a].x, x[b].y - x[a].y, x[c].x - x[b].x, x[c].y - x[b].y);
}

int check(int a, int b, int c) {
    return check_zero(cross(a, b, c));
}

bool compare(const node &a, const node &b) {
    if (a.y < b.y) return true;
    if (a.y == b.y) return a.x < b.x;
    return false;
}


int main() {
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i].x >> x[i].y;
    sort(x+1, x+n+1, compare);
    
    x[0].y = -1e10;
    x[n+1].y = 1e10;
    
    for (int i = 1; i <= n; ++i) {
        if (x[i].y != x[i-1].y) lower.push_back(i);
        if (x[i].y != x[i+1].y) upper.push_back(i);
    }
    
    vector<int> ans_lower;
    ans_lower.push_back(lower[0]);
    ans_lower.push_back(lower[1]);
    int i = 2;
    while (i < lower.size()) {
        if (check(ans_lower[ans_lower.size() - 2], ans_lower[ans_lower.size() - 1], lower[i]) == 1 
            && ans_lower.size() > 1) {
            ans_lower.erase(ans_lower.end() - 1, ans_lower.end());
        } else {
            ans_lower.push_back(lower[i]);
            ++i;
        }
    }
    
    vector<int> ans_upper;
    ans_upper.push_back(upper[0]);
    ans_upper.push_back(upper[1]);
    i = 2;
    while (i < upper.size()) {
        if (check(ans_upper[ans_upper.size() - 2], ans_upper[ans_upper.size() - 1], upper[i]) == -1 
            && ans_upper.size() > 1) {
            ans_upper.erase(ans_upper.end() - 1, ans_upper.end());
        } else {
            ans_upper.push_back(upper[i]);
            ++i;
        }
    }
    
    double ans = 0;
    for (int i = 0; i < ans_lower.size() - 1; ++i)
     ans += sqrt(pow(x[ans_lower[i]].x - x[ans_lower[i+1]].x, 2) + 
                 pow(x[ans_lower[i]].y - x[ans_lower[i+1]].y, 2));
    
    for (int i = 0; i < ans_upper.size() - 1; ++i)
     ans += sqrt(pow(x[ans_upper[i]].x - x[ans_upper[i+1]].x, 2) + 
                 pow(x[ans_upper[i]].y - x[ans_upper[i+1]].y, 2));
    
    ans += sqrt(pow(x[ans_upper[0]].x - x[ans_lower[0]].x, 2) + 
                pow(x[ans_upper[0]].y - x[ans_lower[0]].y, 2));
                
    ans += sqrt(pow(x[ans_upper[ans_upper.size()-1]].x - x[ans_lower[ans_lower.size()-1]].x, 2) + 
                pow(x[ans_upper[ans_upper.size()-1]].y - x[ans_lower[ans_lower.size()-1]].y, 2));
    
    printf("%.2lf\n", ans);
    
    return 0;
}