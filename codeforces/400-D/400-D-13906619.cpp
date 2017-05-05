//In the name of Allah
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<functional>
#include<bitset>
#include<stdio.h> 
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("in.txt"),W_("out.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define sz(v)      (ll)v.size()
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
vvii G;int dp[MAX][MAX];
map<int,int>mp;int vis[100000+7];
int v,h;
void DFS(int node)
{
    vis[node]=h;v+=mp[node+1]==h;
    lop(i,0,sz(G[node]))
    {
        ii child=G[node][i];
        if(vis[child.first]==h||child.second!=0)continue;
        DFS(child.first);
    }
}
int main ()
{
    int n,m,k,N=1;cin>>n>>m>>k;
    G.resize(n);vi vv;
    lop(i,0,MAX)lop(j,0,MAX)dp[i][j]=oo,dp[i][i]=0;
    lop(i,0,k){int c;cin>>c;vv.push_back(c);lop(j,0,c)mp[N++]=i+1;}
    lop(i,0,m)
    {
        int a,b,c;cin>>a>>b>>c;
        if(mp[a]==mp[b]&&c!=0)continue;
        G[a-1].push_back(ii(b-1,c));G[b-1].push_back(ii(a-1,c));
        dp[mp[a]-1][mp[b]-1]=dp[mp[b]-1][mp[a]-1]=min(c,dp[mp[b]-1][mp[a]-1]);
    }
    N=0;
    lop(i,0,k){h=i+1;v=0;DFS(N);N+=vv[i];if(v!=vv[i])return(cout<<"No\n",0);}
    lop(u,0,k)lop(i,0,k)lop(j,0,k)dp[i][j]=min(dp[i][j],dp[i][u]+dp[u][j]);
    cout<<"Yes\n";
    lop(i,0,k){lop(j,0,k)(dp[i][j]==oo)?printf("-1 "):printf("%d ",dp[i][j]);cout<<endl;}
}