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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
int vis[MAX],d[MAX],pre[MAX],n,m,k,printed=0;vvi G;
void DFS(int node,int prev,int dep)
{
    vis[node]=DFS_GRAY,pre[node]=prev,d[node]=dep;
    lop(i,0,sz(G[node]))
    {
        int child=G[node][i];
        if(vis[child]==DFS_GRAY&&child!=prev&&!printed&&dep-d[child]>=k)
        {
            int x=node;vi path;printed=1;
            while(x!=child){path.push_back(x+1);x=pre[x];}
            path.push_back(child+1);
            cout<<sz(path)<<endl;
            loop(k,sz(path),0)cout<<path[k]<<" ";cout<<endl;
            return;
        }
        if(vis[child]==DFS_WHITE)DFS(child,node,dep+1);
    }
    vis[node]=DFS_BLACK;
}
int main()
{
    cin>>n>>m>>k;G.resize(n);
    lop(i,0,m){int a,b;cin>>a>>b;--a,--b;G[a].push_back(b),G[b].push_back(a);}
    memset(pre,-1,sizeof pre);
    DFS(0,-1,0);
}