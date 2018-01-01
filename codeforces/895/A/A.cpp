#include <bits/stdc++.h>

using namespace std;
int pref[360][360];
int arr[360];
int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) {
        cout << 360 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
		cin >> arr[i];
    }
    int minDis = 180;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				if(abs(180-arr[i]) < minDis) {
					minDis = abs(180-arr[i]);
				}
			}
			if(i > j) {
				int sum = 0;
				for(int k = j; k < n; k++) {
					sum += arr[k];
				}
				for(int k = 0; k <= i; k++) {
					sum += arr[k];
				}
				if(abs(180-sum) < minDis) {
					minDis = abs(180-sum);
				}
			}
			if(j > i) {
				int sum = 0;
				for(int k = i; k <= j; k++) {
					sum += arr[k];
				}
				if(abs(180-sum) < minDis) {
					minDis = abs(180-sum);
				}
			}
		}
	}
	cout << 2*minDis << endl;
}
