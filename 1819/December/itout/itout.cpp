#include <bits/stdc++.h>
using namespace std;
#define tab "\t"
int arr[100000];
vector<pair<int,int> > inversions;
vector<pair<int,set<int> > > sols;


bool check(pair<int,set<int> > a, pair<int, set<int> > b) {
    if(a.first != b.first) return a.first < b.first;
    set<int>::iterator it1 = a.second.begin();
    set<int>::iterator it2 = b.second.begin();
    while(true) {
        if(it1 == a.second.end() || it2 == b.second.end()) break;
        if(*it1 != *it2) return *it1 < *it2;
        it1++;
        it2++;
    }
    return true;
}

int main() {
    freopen("itout.in","r",stdin);
    freopen("itout.out","w",stdout);
    int N;
    long long K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(arr[i] > arr[j]) {
                inversions.push_back(make_pair(arr[i],arr[j]));
            }
        }
    }   
    for(int i = 0; i < (1 << N); i++) {
        set<int> temp;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                temp.insert(j+1);
            }
        }
        bool flag = false;
        for(int j = 0; j < inversions.size(); j++) {
            int f = inversions[j].first;
            int s = inversions[j].second;
            if(temp.find(f) == temp.end() && temp.find(s) == temp.end()) {
                flag = true;
                break;
            }
        }
        if(flag) {
          continue;
        }
        sols.push_back(make_pair(temp.size(), temp));
    }

    sort(sols.begin(), sols.end(), check);
    pair<int,set<int> > sol = sols[K-1];
    cout << sol.first << endl;
    for(int x:sol.second) {
        cout << x << endl;
    }
}
