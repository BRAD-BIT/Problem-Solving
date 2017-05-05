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
int const MAX = 123456 + 7;
int const MOD = 1000000007;
vvi G;vi attack;int is_attack[MAX],vis[MAX],valid[MAX]={1};
map<ii,int>mem;int e=0;
int  DFS1(int node)
{
    vis[node]=1;valid[node]=0;e++;
    lop(i,0,sz(G[node]))
    {
        int child=G[node][i];
        if(!vis[child]&&valid[child])valid[node]|=DFS1(child);
    }
    valid[node]|=is_attack[node];
    return valid[node];
}
int DFS2(int cur,int from)
{
    if(mem.count(ii(cur,from))!=0)return mem[ii(ii(cur,from))];
    lop(i,0,sz(G[cur]))
    {
        int child=G[cur][i];
        if(child==from||!valid[child])continue;
        mem[ii(ii(cur,from))]=max(mem[ii(ii(cur,from))],DFS2(child,cur)+1);
    }
    return mem[ii(ii(cur,from))];
}
int main ()
{
    int n,m;cin>>n>>m;G.resize(n);
    lop(i,0,n-1){int a,b;cin>>a>>b;a--,b--;G[a].push_back(b),G[b].push_back(a);valid[i+1]=1;}
    lop(i,0,m){int a;cin>>a;a--;attack.push_back(a);is_attack[a]=1;}
    DFS1(attack[0]);memset(vis,0,sizeof vis);DFS1(attack[0]);
    e-=n+1;sort(all(attack));ii ans(0,attack[0]);
    lop(i,0,sz(attack)){int d=DFS2(attack[i],-1);
    if(d>ans.first)ans=ii(DFS2(attack[i],-1),attack[i]);}
    cout<<ans.second+1<<"\n"<<2*e-ans.first<<endl;
}