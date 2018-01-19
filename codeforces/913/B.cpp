#include <bits/stdc++.h>
using namespace std;
typedef map<int, int> mii;
typedef map<int, vector<int> > mivi;
// 1 indexed
bool leaf[1001];
mii parent;
mivi child;

int main() {
    int n;
    cin >> n;
    for(int i= 1; i <= n; i++) {
        leaf[i] = true;
        vector<int> l;
        child.insert(make_pair(i,l));
    }
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        parent.insert(make_pair(i,x));
        leaf[x] = false;
        child[x].push_back(i);
    }
    bool allGood = true;
    for(int i = 1; i <= n; i++) {
        if(!leaf[i]) {
            vector<int> temp = child[i];
            int count = 0;
            for(int j = 0; j < temp.size(); j++) {
                if(leaf[temp[j]]) {
                    count += 1;
                }   
            }
            if(count < 3) {
                allGood = false;
                break;
            }
        }
    }
    if(allGood) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}
