#include <bits/stdc++.h>

using namespace std;
int arr[100000];
int main() {
    int n;
    cin >> n;
    int curmax;
    int losttomax = 0;
    int maxlost = -1;
    int secondmaxnum = -1;
    int maxnum = -1;
    int actmax = -1;
    cin >> arr[0];
    curmax = arr[0];
    secondmaxnum = -1;
    actmax = arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        //cout << arr[i] << "  " << curmax << "  " << losttomax << "  " << maxlost << "  " << secondmaxnum << "  " << maxnum << "  " << actmax << endl;
        if(arr[i] > actmax) {
            if(losttomax > maxlost) {
                maxlost = losttomax;
                secondmaxnum = actmax;
                maxnum = curmax;
                curmax = arr[i];
                actmax = arr[i];
                losttomax = 0;
            }
            else {
                losttomax = 0;
                secondmaxnum = actmax;
                actmax = arr[i];
                curmax = arr[i];
            }
        }
        else if(arr[i] > secondmaxnum) {
            secondmaxnum = arr[i];
            losttomax += 1;
        }
    }
    if(losttomax > maxlost) {
        maxlost = losttomax;
        maxnum = curmax;
        curmax = arr[n-1];
    }
    cout << maxnum << endl;

}
