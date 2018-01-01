#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    if(x0 == x1) {
        cout << (6+2*abs(y0-y1)) << endl;
    }
    else if(y0 == y1) {
        cout << (6+2*abs(x0-x1)) << endl;
    }
    else {
        cout << 2*(2+abs(x0-x1) + abs(y0-y1)) << endl;
    }
}
