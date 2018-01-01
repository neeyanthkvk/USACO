#include <bits/stdc++.h>

using namespace std;

typedef pair<int,double> pii;
typedef vector<pii> vpii;

vpii centers;

int main() {
    int n, r;
    cin >> n >> r;
    cout.precision(17);    
    int first;
    cin >> first;
    pii firstcen = make_pair(first, r);
    centers.push_back(firstcen);
    cout << r;
    for(int i = 1; i < n; i++) {
        int newx;
        cin >> newx;
        double maxdis = r;
        for(int j = 0; j < centers.size(); j++) {
            pii tempcen = centers[j];
//            cout << tempcen.first << "\t" << tempcen.second << endl;
            if(abs(newx-tempcen.first) > 2*r) continue;
            double temp  = sqrt(4*r * r - (newx-tempcen.first) * (newx-tempcen.first)) + tempcen.second;
//            cout << temp << endl;
            if(temp > maxdis) {
                maxdis = temp;
            }
        }
        cout << " " << maxdis;
        centers.push_back(make_pair(newx,maxdis));
    }
    cout << endl;
}
