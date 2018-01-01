/*
ID: neeyant2
TASK: buylow
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;
int n,ansv=0;
const int BASE=100000000;
long long a[5001]={0};
int f[5001]={0},ago[5001]={0};
int sum[5001][100]={0};
void add(int x,int y)
{
    int l=max(sum[x][0],sum[y][0]);
    sum[x][0]=l;
    for(int i=1;i<=l;++i)
    {
        sum[x][i]+=sum[y][i];
        if(sum[x][i]>=BASE)
        {
            sum[x][i+1]+=sum[x][i]/BASE;
            sum[x][i]%=BASE;
        }
    }
    if(sum[x][l+1]) ++sum[x][0];
}
void print(int x)
{
    cout<<sum[x][sum[x][0]];
    for(int i=sum[x][0]-1;i>=1;--i)
    {
        int xx=sum[x][i],l=0;
        while(xx) {++l;xx/=10;}
        if(l==8) cout<<sum[x][i];
        else {
            for(int i=1;i<=8-l;++i) cout<<0;
            if(l) cout<<sum[x][i];
        }
    }
}
int main()
{
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        f[i]=0;
        for(int j=1;j<i;++j)
        {
            if(a[j]==a[i]) ago[i]=j;
            if(f[j]+1>f[i]&&a[j]>a[i]) f[i]=f[j]+1;
        }
        if(f[i]==0) f[i]=1;
        if(f[i]>ansv) ansv=f[i];
    }
    for(int i=1;i<=n;++i)
    {
        if(f[i]==1&&ago[i]==0) {sum[i][1]=1;sum[i][0]=1;}
        else
            for(int j=ago[i]+1;j<i;++j)
            {
                if(f[j]+1==f[i]&&a[j]>a[i]) add(i,j);
            }
    }
    for(int i=1;i<=n;++i)
    {
        if(f[i]==ansv) add(0,i);
    }
    cout<<ansv<<" ";
    print(0);
    cout<<endl;
    return 0;
}