/*
ID: neeyant2
PROG: fence6
LANG: C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100;
const int oo=0x7fffffff;

int re=oo,n;
int g[MAXN][MAXN];
int dis[MAXN][MAXN];
int n1[MAXN],n2[MAXN],len[MAXN];
int li[MAXN][MAXN],ri[MAXN][MAXN];

int main()
{
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g[i][j]=oo,dis[i][j]=oo;
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		scanf("%d",&a);
		--a;
		scanf("%d%d%d",len+a,n1+a,n2+a);
		for(int j=0;j<n1[a];j++)
		{
			scanf("%d",li[a]+j);
			li[a][j]--;
		}
		for(int j=0;j<n2[a];j++)
		{
			scanf("%d",ri[a]+j);
			ri[a][j]--;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n1[i];j++)
		{
			int v=li[i][j];
			g[i][v]=dis[i][v]=len[i]+len[v];
		}
		for(int j=0;j<n2[i];j++)
		{
			int v=ri[i][j];
			g[i][v]=dis[i][v]=len[i]+len[v];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n1[k];i++)
		{
			int ii=li[k][i];
			if (ii<k)
			{
				for(int j=0;j<n2[k];j++)
				{
					int jj=ri[k][j];
					if (jj<k&&dis[ii][jj]!=oo)
						re=min(re,g[ii][k]+g[k][jj]+dis[ii][jj]);
				}
			}
		}
		for(int i=0;i<n;i++)
			if (dis[i][k]!=oo)
			for(int j=0;j<n;j++)
				if (dis[k][j]!=oo)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	printf("%d\n",re/2);
	return 0;
}
