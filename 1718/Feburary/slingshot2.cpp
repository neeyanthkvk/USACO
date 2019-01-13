#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<pair<int, pii> > tract;
const int MOD = 1000000007;
int N,M;

int binSearch(int initial) {
    int index = -1;
    int min = 2147483647;
    int low = 0;
    int high = N-1;
    while(abs(low-high) > 1) {
        int mid = (low+high)/2;
        int temp = tract[mid].first;
        if(abs(initial-temp) < min) {
            index = mid;
            min = abs(initial-temp);
        }
        if(temp > initial) high = mid;
        else low = mid;
    }
    if(high == low) {
        int index = low;
        int temp = tract[index].first;
        if(abs(initial-temp) < min) {
            index = temp;
            min = abs(initial-temp);
        }
    }
    if(high > low) {
        int curr = low;
        int temp = tract[curr].first;
        if(abs(initial-temp) < min) {
            index = curr;
            min = abs(initial-temp);
        }
		curr = high;
		temp = tract[curr].first;
        if(abs(initial-temp) < min) {
            index = curr;
            min = abs(initial-temp);
        }
    }
	return index;
}

int ans(int x, int y, int index) {
    return abs(tract[index].first-x) + abs(tract[index].second.first-y) + tract[index].second.second;
}

int main() {
    freopen("slingshot.in","r",stdin);
    freopen("slingshot.out","w",stdout);
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        tract.push_back(make_pair(a,make_pair(b,c)));
    }
    sort(tract.begin(), tract.end());
    for(int i = 0; i < M; i++) {
        int x,y;
        scanf("%d %d", &x,&y);
        int min = abs(x-y);
        int index = binSearch(x);
        int currIndex = index - 1;
        int tempAns = ans(x,y,index);
        min = min > tempAns ? tempAns:min;
        while(currIndex >= 0) {
            int xx = tract[currIndex].first;
            if(abs(x-xx) >= min) break;
            tempAns = ans(x,y,currIndex);
            min = min > tempAns ? tempAns:min;
            currIndex--;
        }
        currIndex = index + 1;
        while(currIndex < N) {
            int xx = tract[currIndex].first;
            if(abs(x-xx) >= min) break;
            tempAns = ans(x,y,currIndex);
            min = min > tempAns ? tempAns:min;
            currIndex++;
        }
        cout << min << "\n";
    }
    return 0;

}