#include <bits/stdc++.h>

using namespace std;

struct comp {
    bool operator() (pair<int, int> x, pair<int, int> y) {
        if(x.first < y.first) {
            return true;
        }
        if(x.first > y.first) {
            return false;
        }
        return x.second > y.second;
    }
}myobj;

pair<int, int> nums[200000];

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        int a, b;
        cin >> temp;
        float root = sqrt((float) temp);
        int f = (int) root;
        int c = f+1;
        if(c*c-temp > temp-f*f) {
            b = temp-f*f;
        }
        else {
            b = c*c-temp;
        }
        if(b == 0 && temp != 0) {
            a = 1;
        }
        else if(temp == 0) {
            a = 2;
        }
        else if(b != 0) {
            a = 0; 
        }
        nums[i] = make_pair(b, a);
    }
    sort(nums, nums+N, myobj);
    long long answer = 0;
    for(int i = 0; i < N/2; i++) {
        answer += nums[i].first;
    }
    for(int i = N/2; i < N; i++) {
        answer += nums[i].second;
    }
    cout << answer;
}
