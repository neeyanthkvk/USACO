#include <bits/stdc++.h>
using namespace std;
#define MAXN 70500
#define BSIZE 141
#define MAX_BLOCKS 500

vector<int> edges[MAXN];
int distLeaf[MAXN];
int distStart[MAXN];
int startLoc[MAXN], endLoc[MAXN];
int C;

void dfsDistances(int i,int par)
{
	distLeaf[i] = MAXN + 1;
	if(par != -1)
		distStart[i] = 1 + distStart[par];
	else
		distStart[i] = 0;
	for(int j=0;j<edges[i].size();j++)
		if(par != edges[i][j])
		{
			dfsDistances(edges[i][j],i);
			distLeaf[i] = min(distLeaf[i], 1 + distLeaf[edges[i][j]]);
		}
	if(edges[i].size()==1)
		distLeaf[i] = 0;
}

void dfsDistances2(int i,int par)
{
	if(par!=-1)
		distLeaf[i] = min(distLeaf[i],distLeaf[par]+1);
	for(int j=0;j<edges[i].size();j++)
		if(par!=edges[i][j])
			dfsDistances2(edges[i][j],i);
}

void dfsOrder(int i,int par)
{
	startLoc[i] = C++;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			dfsOrder(edges[i][j],i);
	endLoc[i] = C-1;
}

int val[MAXN],key[MAXN];
int lazy[MAX_BLOCKS];
int overallLazy;
int T[MAX_BLOCKS][2*MAXN];

void update(int block,int i,int d)
{
	for(i++;i<2*MAXN;i+=(i&-i))
		T[block][i] += d;
}
long long getSum(int block,int i)
{
	long long c = 0;
	for(i++;i>0;i-=(i&-i))
		c += T[block][i];
	return c;
}

void unbuildBlock(int b,int x,int y)
{
	for(int i=x;i<=y;i++)
		update(b,key[i],-val[i]);
}

void rebuildBlock(int b,int x,int y)
{
	for(int i=x;i<=y;i++)
		update(b,key[i],val[i]);
}

void updateKey(int low,int high,int dif)
{
	int ilow = low;
	int ihigh = high;
	int blockLow = low/BSIZE;
	int blockHigh = high/BSIZE;
	if(blockLow == blockHigh)
	{
		unbuildBlock(blockLow,low,high);
		while(low<=high)
			key[low++] += dif;
		rebuildBlock(blockLow,ilow,ihigh);
		return;
	}
	unbuildBlock(blockLow,ilow,BSIZE*(ilow/BSIZE) + BSIZE-1);
	unbuildBlock(blockHigh,BSIZE*(ihigh/BSIZE),ihigh);
	while(low != (blockLow+1)*BSIZE)
		key[low++] += dif;
	while(high != blockHigh*BSIZE-1)
		key[high--] += dif;
	rebuildBlock(blockLow,ilow,BSIZE*(ilow/BSIZE) + BSIZE-1);
	rebuildBlock(blockHigh,BSIZE*(ihigh/BSIZE),ihigh);
	for(int b=blockLow+1;b<blockHigh;b++)
		lazy[b] += dif;
}

long long getTotalSum()
{
	long long sm = 0;
	for(int b=0;b<MAX_BLOCKS;b++)
		sm += getSum(b,MAXN-lazy[b]-overallLazy);
	return sm;
}

int ans[MAXN];
int N;

void dfs(int i,int par)
{
	ans[i] = getTotalSum();
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
		{
			updateKey(startLoc[edges[i][j]], endLoc[edges[i][j]], 2);
			overallLazy--;
			dfs(edges[i][j],i);
			overallLazy++;
			updateKey(startLoc[edges[i][j]], endLoc[edges[i][j]], -2);
		}
}



int main()
{
	int a,b;
	cin >> N;
	for(int i=1;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfsDistances(0,-1);
	dfsDistances2(0,-1);
	dfsOrder(0,-1);
	for(int i=0;i<N;i++)
	{
		val[startLoc[i]] = 2 - (int)edges[i].size();
		key[startLoc[i]] = distLeaf[i] - distStart[i] + MAXN;
	}
	for(int b=0;b<MAX_BLOCKS;b++)
		rebuildBlock(b,BSIZE*b,BSIZE*(b+1)-1);
	dfs(0,-1);
	int mdif = 0;
	for(int i=0;i<N;i++)
	{
		if(edges[i].size()==1)
			ans[i] = 1;
		cout << ans[i] << '\n';
	}
}