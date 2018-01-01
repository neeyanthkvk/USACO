/*
ID: neeyant2
TASK: race3
LANG: C++
*/
#include<iostream>
#include<cstdio>
using namespace std;
int a[51][51],n,ans1=0,ans2=0;
int q[100]={0},m[100]={0},he,ta;
int re[100]={0};
int main()
{
    freopen("race3.in","r",stdin);
    freopen("race3.out","w",stdout);
    int x;n=0;
    while(1)
    {
        cin>>x;
        if(x>=0) a[n][x]=1;
        else if(x==-1) break;
        else if(x==-2) ++n;
    }
    --n;
    m[0]=1;q[1]=0;he=ta=1;
    while(he<=ta)
    {
        if(he==ta)
        {
            re[q[he]]=1;++ans1;
            int ff=1;
            for(int i=0;i<=n&&ff;++i)
                for(int j=0;j<=n;++j)
                    if(m[i]!=m[j]&&a[i][j]&&i!=q[he]&&j!=q[he]) {ff=0;break;}
            if(ff)
            {
                for(int i=0;i<=n;++i) if(m[i]&&a[q[he]][i]&&i!=q[he]) {ff=0;break;}
            }
            if(ff) {re[q[he]]=2;++ans2;}
        }
        x=q[he++];
        for(int i=0;i<=n;++i)
            if(!m[i]&&a[x][i]) {q[++ta]=i;m[i]=1;}
    }
    cout<<ans1-2;
    for(int i=1;i<n;++i) if(re[i]) cout<<" "<<i;
    cout<<endl;
    cout<<ans2-2;
    for(int i=1;i<n;++i) if(re[i]==2) cout<<" "<<i;
    cout<<endl;
    return 0;
}