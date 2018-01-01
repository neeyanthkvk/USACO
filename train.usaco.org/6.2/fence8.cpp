/*
TASK: fence8
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,mm,m=0,totb=0,maxb=0,can,lj,limit;
int b[51]={0},r[1024]={0},sr[1024]={0};
void dfs(int k,int s)
{
    if(k<1) {can=1;return;}
    if(can) return;
    if(lj+sr[limit]>totb) return;
    for(int i=s;i>=1&&!can;--i)
    {
        if(b[i]>=r[k])
        {
            b[i]-=r[k];
            if(b[i]<r[1]) lj+=b[i];
            if(r[k]==r[k-1]) dfs(k-1,i);
            else dfs(k-1,n);
            if(b[i]<r[1]) lj-=b[i];
            b[i]+=r[k];
        }
    }
}
int main()
{
    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
        totb+=b[i];
        if(b[i]>maxb) maxb=b[i];
    }
    sort(b+1,b+n+1);
    cin>>mm;int tmp;
    for(int i=1;i<=mm;++i)
    {
        cin>>tmp;
        if(tmp<=maxb)
        {
            r[++m]=tmp;
        }
    }
    sort(r+1,r+m+1);
    for(int i=1;i<=m;++i) sr[i]=sr[i-1]+r[i];
    for(int i=1;i<=m;++i)
    {
        limit=i;
        int ok=1;
        if(sr[i]>totb) ok=0;
        if(ok)
        {
            lj=0;
            can=0;
            dfs(i,n);
            ok=can;
        }
        if(!ok) {cout<<i-1<<endl;return 0;}
    }
    cout<<m<<endl;
    return 0;
}