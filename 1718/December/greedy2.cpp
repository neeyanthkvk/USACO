#include <bits/stdc++.h>

using namespace std;
list<int> place;
map<int, int> seen;
int skip[100001];
bool found[100002];
set<int> visited;
int main() {
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> skip[i];
        place.push_back(i);
    }
    while(true) {
		int curr = place.front();
		if(visited.find(curr) != visited.end()) {
			if(visited.size() == seen[curr]) {
				break;
			}
			else {
				seen[curr] = visited.size();
			}
		}
        visited.insert(curr);
        seen.insert(make_pair(curr,visited.size()));
        place.pop_front();
        found[curr] = true;
        int skips = skip[curr];
        list<int>::iterator it = place.begin();
        for(int i = 0; i < n-skips-1; i++) {
            it++;
        }
        place.insert(it,curr);
    }
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(!found[i]) {
            answer += 1;
        }
    }
    cout << answer << endl;
}
