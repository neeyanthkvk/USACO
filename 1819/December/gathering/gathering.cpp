#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > frien;
unordered_set<int> graph[100000];
bool hasFriend[100000];
bool recur[100000];
bool visited[100000];
vector<pair<int,int> > edges;
bool isGood[100000];
bool isFinal[100000];


bool hasCycle(int curr) {
    visited[curr] = true;
    recur[curr] = true;
    for(int child:graph[curr]) {
        if(!visited[child] && hasCycle(child)) return true;
        else if(recur[child]) return true;
    }
    recur[curr] = false;
    return false;
}

int main() {
    freopen("gathering.in","r",stdin);
    freopen("gathering.out","w",stdout);
    int N,M;
    memset(isFinal, false, sizeof(bool)*100000);
    cin >> N >> M;
    for(int i = 0; i < N-1; i++) {
        int a,b;
        cin >> a >> b;
        frien.push_back(make_pair(a-1,b-1));
        hasFriend[a-1] = true;
        hasFriend[b-1] = true;
        edges.push_back(make_pair(a-1,b-1));
    }
    for(int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        graph[a-1].insert(b-1);
    }
    bool h = false;
    for(int i = 0; i < N; i++) {
        bool t = hasCycle(i);
        if(t) {
            h = true;
            break;
        }
    }
    if(h) {
        for(int i = 0; i < N; i++) {
            cout << 0 << endl;
        }
    }
    else {
        for(int i = 0; i < N; i++) {
            isGood[i] = ((graph[i].size() == 0) && (hasFriend[i]));
        }
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i].first;
            int b = edges[i].second;
            if(isGood[a]) isFinal[b] = true;
            else {
                if(graph[a].size() == 1 && b == *graph[a].begin()) {
                    isFinal[b] = true;
                }   
            }
            if(isGood[b]) isFinal[a] = true;
            else {
                if(graph[b].size() == 1 && a == *graph[b].begin()) {
                    isFinal[a] = true;
                }
            }
        }
        for(int i = 0; i < N; i++) {
            cout << (isGood[i] && isFinal[i]) << endl;
        }
    }
}
