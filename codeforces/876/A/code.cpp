#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    n = n-1;
    if(a < c or b < c) {
        if(a < b) {
            cout << n*a;
        }
        else {
            cout << n*b;
        }
    }
    else {
        if(a < b) {
            if(n == 0) {
                cout << 0;
            }
            else {
                cout << (a+(n-1)*c);
            }
        }
        else {
            if(n == 0) { 
                cout << 0;
            }
            else {
                cout << (b+(n-1)*c);
            }
        }
    }
    cout << endl;
}
