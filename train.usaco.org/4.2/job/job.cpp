/*
 ID: neeyant2
 LANG: C++
 TASK: job
 */
#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

int main()
{
	freopen("job.in","rt",stdin);
	freopen("job.out","wt",stdout);
	
	int N, M1, M2, t;
	vector <int> mA, mB;
	
	scanf("%d%d%d",&N,&M1,&M2);
    for(int i=0;i<M1;i++) {
        scanf("%d",&t);
		mA.push_back(t);
	}
	for(int i=0;i<M2;i++) {
		scanf("%d",&t);
		mB.push_back(t);
	}

	vector <int> aJobsTime(N+1,0);
	vector <int> aMachTime(M1, 0);
	for(int i=1;i<=N;i++) {

		int minF = INF, index = -1;
		for(int j=0;j<M1;j++) {

			if( minF > aMachTime[j] + mA[j] ) { 
				minF = aMachTime[j]+mA[j];
				index = j;
			}
		}
		aJobsTime[i] = minF;
		aMachTime[index] += mA[index];
	}

	vector <int> bJobsTime(N+1,0);
	vector <int> bMachTime(M2, 0);
	for(int i=1;i<=N;i++) {

		int minF = INF, index = -1;
		for(int j=0;j<M2;j++) {

			if( minF > bMachTime[j] + mB[j]) {
				minF = bMachTime[j] + mB[j];
				index = j;
			}
		}
		bJobsTime[i] = minF;
		bMachTime[index] += mB[index];
	}

	int result = -1;
	for(int i=1;i<=N;i++) {

		if( result < bJobsTime[i] + aJobsTime[N-i+1] )
			result = bJobsTime[i] + aJobsTime[N-i+1];
	}
	printf("%d %d\n", aJobsTime[N], result);
}
