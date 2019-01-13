#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    double min = 1000000.0;
    for(int i = 0; i < a; i++) {
        double x,y;
        cin >> x >> y;
        min = double(x/y) >= min ? min : double(x/y);
    }
    cout << setprecision(8) << b * min << endl;
    return 0;
}
