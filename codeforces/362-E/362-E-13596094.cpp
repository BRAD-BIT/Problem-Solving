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
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 0, 1, -1, -1, -1, -1, 1, 1 };
int dc[] = { 1, 1, 1, 0, -1, 1, -1, 1 };
int const MAX = 50 + 7;
int const MOD = 1e9 + 7;
struct edge{int indx,cost;edge(int i,int C):indx(i),cost(C){};
bool operator<(edge e)const{return e.cost<cost;}
};
int n,k;vector<vector<edge>>G;ll vis[MAX],dis[MAX],cap[2][MAX][MAX];ii prv[MAX];
int max_flow(int s,int t)
{
    int mf = 0; 
    while (1)
    {
        priority_queue<edge>q; q.push(edge(s,0)); 
        memset(vis, 0, sizeof vis); 
        lop(i,0,n)dis[i]=oo,prv[i]=ii(-1,-1);
        dis[s]=0;
        while (!q.empty())
        {
            edge cur = q.top(); q.pop();
            if(vis[cur.indx])continue;
            vis[cur.indx]=1;
            for(int i=0;i<sz(G[cur.indx]);++i)
            {
                edge child=G[cur.indx][i];
                if(cap[child.cost][cur.indx][child.indx]<=0)continue;
                if(dis[child.indx]<=dis[cur.indx]+child.cost)continue;
                dis[child.indx]=dis[cur.indx]+child.cost;
                prv[child.indx].first=cur.indx;
                prv[child.indx].second=child.cost;
                q.push(edge(child.indx,dis[child.indx]));
            }
        }
        if(prv[t].first==-1||dis[t]>k)return mf;
        k-=dis[t];
        vector<ii>path;
        int i = t;
        path.push_back(ii(t,-1));
        while (prv[i].first!=-1)
        {
            path.push_back(prv[i]);
            i = prv[i].first;
        }
        reverse(path.begin(), path.end());
        ll mn = oo;
        if(dis[t]!=0)mn=1;
        else
            for (int i = 0; i < path.size() - 1; i++)mn = min(mn, cap[0][path[i].first][path[i + 1].first]);
        for (int i = 0; i < path.size() - 1; i++)
        {
            cap[path[i].second][path[i].first][path[i + 1].first] -= mn;
            cap[path[i].second][path[i + 1].first][path[i].first] += mn;
        }
        mf += mn;
    }
}
int main()
{
    cin>>n>>k;G.resize(n);
    lop(i,0,n)lop(j,0,n){int a;cin>>a;cap[0][i][j]=a;cap[1][i][j]=oo*a;
    G[i].push_back(edge(j,0));G[i].push_back(edge(j,1));
    }
    int ans=max_flow(0,n-1);
    cout<<ans<<endl;
}