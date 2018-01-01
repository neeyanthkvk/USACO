/*
ID: neeyant2
LANG: C++
PROG: shuttle
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;
#define mp make_pair
#define INF                         (int)1e9
#define X first
#define Y second 
#define rep(i, n)                  for(int i=0; i < n; i++)
#define range(i, a, b)                for(int i=a; i < b; i++)
#define fill(a, x)                 memset(a, x, sizeof(a))
#define all(c)                     c.begin(), c.end()
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int selected[100000] = {0}, maxdepth = 0;
string goal;
bool found;
int ctr = 0;
void search(const string state, int depth) {
    if (found) return;
    if (state == goal) {
        ctr++;
        found = true;
        maxdepth = (maxdepth  - depth);
        return;
    }
    
    if (depth == 0) return;

    int space = 0;
    while (state[space] != ' ') space++;
    assert(space != state.length());

    int slen = state.length();
    
    if (!found && space > 1 && state[space-2] == 'W' && state[space-1] == 'B') {
        string copy(state);
        copy[space-2] = ' ';
        copy[space] = 'W';
        selected[maxdepth - depth] = space - 1;
        search(copy, depth-1);
    }

    if (!found && space > 0 && state[space-1] == 'W') {
        string copy(state);
        copy[space-1] = ' ';
        copy[space] = 'W';
        selected[maxdepth - depth] = space;
        search(copy, depth-1);
    }

    if (!found && space < (slen - 1) && state[space+1] == 'B') {
        string copy(state);
        copy[space+1] = ' ';
        copy[space] = 'B';
        selected[maxdepth - depth] = space + 2;
        search(copy, depth-1);
    }

    if (!found && space < (slen - 2) && state[space+2] == 'B' && state[space+1] == 'W') {
        string copy(state);
        copy[space+2] = ' ';
        copy[space] = 'B';
        selected[maxdepth - depth] = space + 3;
        search(copy, depth-1);
    }
}


int main() {
    ifstream fin("shuttle.in");
    ofstream fout("shuttle.out");
    int N;
    fin >> N;
    goal = string(N, 'B') + " " + string(N, 'W');
    string start = string(N, 'W') + " " + string(N, 'B');
    for(int i=1; i < 2000; i*=2) {
        maxdepth = i;
        found = false;
        search(start, i);
        if (found) break;
    }
    assert(maxdepth > 0);
    assert(maxdepth < 100000);
    assert(found);
    cout << maxdepth << endl;
    range(i, 0, maxdepth) {
        if (i % 20 == 19 || i == maxdepth - 1) fout << selected[i] << endl;
        else fout << selected[i] << " "; 
    }
    printf("%d\n", ctr);
    return 0;
}