/*
ID: neeyant2
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
//#include "debug.cpp"

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define REPS(i,m,n) for(int (i)=(m);(i)<(int)(n);++(i))
#define FE(i, x) for(typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define BITS(var,pos) ((var) & (1<<(pos)))
#define ALL(x) x.begin(), x.end()
#define INF 99999999

int scan(){
    int t;
    scanf("%d", &t);
    return t;
}

int main(){
    freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
    int dxkn[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dykn[8] = {1,  -1,  2, -2, 2,-2, 1,-1};

    int R, C; scanf("%d %d\n", &R, &C);
    int memoknight[R][C][R][C]; 
    REP(i, R) REP(j, C) REP(ii, R) REP(jj, C) memoknight[i][j][ii][jj] = INF;

    int memoking[R][C]; REP(i, R) REP(j, C) memoking[i][j] = INF; 

    REP(i, R) REP(j, C){
        memoknight[i][j][i][j] = 0; //where can a knight at i, j get to?
        bool set=true;
        while (set){
            set = false;
            REP(k, R) REP(l, C){
                if (memoknight[i][j][k][l] != INF){
                    REP(m, 8){
                        int nk = k+dxkn[m];
                        int nl = l+dykn[m];
                        if (nk<0 || nk >=R || nl<0 || nl>=C) continue;
                        if (memoknight[i][j][nk][nl] != INF && memoknight[i][j][nk][nl]  <= memoknight[i][j][k][l] + 1) continue;
                        set=true;
                        memoknight[i][j][nk][nl] = memoknight[i][j][k][l]+1;
                    }
                }
            }
        }
    }

    char a; int b;
    scanf("%c %d\n", &a, &b);
    pair<int, int> kpos = make_pair(b - 1, a - 'A');

    REP(i, R) REP(j, C) memoking[i][j] = max(abs(i-kpos.first), abs(j - kpos.second)); //memoize the king. that was easy...

    vector<pair<int, int> > kns;
    while( scanf("%c %d\n", &a, &b) != EOF){
        kns.push_back(make_pair(b - 1, a - 'A'));
    }

    //Case when no one gets the king

    int board1[R][C]; REP(i, R) REP(j, C) board1[i][j] = memoking[i][j];

    REP(k, kns.size()) REP(i, R) REP(j, C) board1[i][j] += memoknight[kns[k].first][kns[k].second][i][j];

    int MIN = INF;

    REP(i, R) REP(j, C) MIN = min(MIN, board1[i][j]);
    //cout << MIN << endl;
    

    int knightrescue[R][C];
    int withoutkk[R][C];
    REP(k, kns.size()){
        REP(i, R) REP(j, C) withoutkk[i][j] = board1[i][j] - memoking[i][j] - memoknight[kns[k].first][kns[k].second][i][j];
        //Case when knight k gets the king

        REP(i, R) REP(j, C) knightrescue[i][j] = memoknight[kns[k].first][kns[k].second][i][j] + memoking[i][j];
        int bestrescue = INF; REP(i, R) REP(j, C) bestrescue = min(bestrescue, knightrescue[i][j]);

        //It's like we have another knight at the bestrescue position
        REP(i, R) REP(j, C){
            if (knightrescue[i][j] == bestrescue){
                REP(ii, R) REP(jj, C){
                    MIN = min(MIN, withoutkk[ii][jj] + memoknight[i][j][ii][jj] + bestrescue);
                }
            }
        }
    }

    cout << MIN << endl;

    return 0;
}