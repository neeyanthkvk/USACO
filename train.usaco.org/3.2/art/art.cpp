#include <iostream>
#include <fstream>
#define MAX_N 1000
#define MAX_C (MAX_N*MAX_N)
using namespace std;

int upper[MAX_C+1], lower[MAX_C+1], leftside[MAX_C+1], rightside[MAX_C+1];
int N, total, art[MAX_N+1][MAX_N+1], count[MAX_C+1];
int P[MAX_N+1][MAX_N+1], A[MAX_N+1][MAX_N+1];

int main(void)
{
  ifstream fin("art.in");
  ofstream fout("art.out");
  fin >> N;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      fin >> art[i][j];
  for (int i=1; i<=N*N; i++)
    upper[i] = leftside[i] = N;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++) {
      int c = art[i][j];
      if (c > 0) {
	if (count[c]==0) total++;
	count[c]++;
	upper[c] = min(upper[c], i+1);
	lower[c] = i+1;
	leftside[c] = min(leftside[c], j+1);
	rightside[c] = max(rightside[c], j+1);
      }
    } 
  
  if (total==1) fout << (N == 1 ? 0 : N*N-1) << "\n";
  else {
    int answer = N*N-total;
    for (int c=1; c<=N*N; c++) 
      if (c>0 && count[c]>0) {
	P[lower[c]][rightside[c]]++;
	P[lower[c]][leftside[c]-1]--;
	P[upper[c]-1][rightside[c]]--;
	P[upper[c]-1][leftside[c]-1]++;
      }
    A[N][N] = P[N][N];
    for (int j=N-1; j>=1; j--) 
      A[N][j] = A[N][j+1] + P[N][j];
    for (int i=N-1; i>=1; i--) {
      A[i][N] = A[i+1][N] + P[i][N];
      for (int j=N-1; j>=1; j--) 
	A[i][j] = A[i+1][j] + A[i][j+1] - A[i+1][j+1] + P[i][j];
    }
    for (int i=1; i<=N; i++)
      for (int j=1; j<=N; j++) {
	int c = art[i-1][j-1];
	if (c>0 && count[c]>0 && A[i][j]>=2) count[c] = 0;
      }
    for (int c=1; c<=N*N; c++)
      if (count[c]>0) answer++;
    fout << answer << "\n";
  }
  return 0;
}
