#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
int set_bit(int num,int i,int v){return (v)?(num|(1<<i)):(num&~(1<<i));}
int get_bit(int num,int i){return ((num>>i)&1)==1;}
int cnt_bit(int num){int ret=0;while(num){ret+=(num%2);num/=2;}return ret;}
long long mem[20][(1<<18)+7];
int a[20],C[20][20];
int n,m,k;
long long dp(int last,int mask)
{
    if(cnt_bit(mask)==m)return 0;
    if(mem[last][mask]!=-1)return mem[last][mask];
    long long ans=0;
    for(int j=0;j<n;++j)
    {
        if(!get_bit(mask,j))
            ans=max(dp(j,set_bit(mask,j,1))+C[last][j]+a[j],ans);
    }
    return mem[last][mask]=ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
//freopen("ot.txt", "wt", stdout);
#endif
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<k;i++){int x,y,c;scanf("%d%d%d",&x,&y,&c);C[--x][--y]=c;}
    memset(mem,-1,sizeof mem);

   cout<<dp(19,0)<<endl;
}