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
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
int vis[MAX],prv[MAX],graph1[MAX][MAX],arr[MAX],n;
vvi ans,graph2;vi p;
int max_flow(int s,int t)
{
    int mf = 0; 
    while (1)
    {
        queue<int>q; q.push(s); memset(vis, 0, sizeof vis); memset(prv, -1, sizeof prv);
        vis[s] = 1;
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (int i = 0; i < graph2[cur].size(); i++)
            {
                int child = graph2[cur][i];
                if (!vis[child] && graph1[cur][child]>0)
                {
                    vis[child] = 1; prv[child] = cur; q.push(child); if (child == t)goto NEXT;
                }
            }
        }
    NEXT:
        vector<int>path;
        if (prv[t] == -1)return mf;
        int i = t;
        path.push_back(t);
        while (prv[i] != s)
        {
            path.push_back(prv[i]);
            i = prv[i];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        int mn = oo;
        for (int i = 0; i < path.size() - 1; i++)mn = min(mn, graph1[path[i]][path[i + 1]]);
        for (int i = 0; i < path.size() - 1; i++)
        {
            graph1[path[i]][path[i + 1]] -= mn;
            graph1[path[i + 1]][path[i]] += mn;
        }
        mf += mn;
    }
}
bool IsPrime(int n)
{
    if(n==1||n==0||n%2==0)return 0;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
int VIS[MAX];
void DFS(int node,int pp)
{
    if(VIS[node])return;
    p.push_back(node);
    vis[node]=DFS_GRAY;
    lop(i,0,sz(graph2[node]))
    {
        int d=(arr[node-2]+1)%2;
        int child =graph2[node][i];
        if(graph1[node][child]!=d||VIS[child])continue;

        if(vis[child]==DFS_GRAY&&pp!=child&&p[0]==child)
        {
            lop(k,0,sz(p))VIS[p[k]]=1;ans.push_back(p);
        }

        if(vis[child]==DFS_WHITE)DFS(child,node);
    }
    vis[node]=DFS_BLACK;
    p.pop_back();
}
int main()
{
    int o[2]={0};
    cin>>n;lop(i,0,n){cin>>arr[i];o[arr[i]%2]++;}graph2.resize(n+2);
    if(o[0]!=o[1])return(cout<<"Impossible\n",0);
    lop(i,0,n)
        lop(j,0,n)
        if(i^j)
        if(IsPrime(arr[i]+arr[j])&&arr[i]%2&&arr[j]%2==0)
            graph2[i+2].push_back(j+2),graph2[j+2].push_back(i+2),
            graph1[i+2][j+2]=1;

    lop(i,0,n){if(arr[i]%2)graph2[0].push_back(i+2),graph2[i+2].push_back(0),graph1[0][i+2]=2;
    else{graph2[i+2].push_back(1),graph2[1].push_back(i+2),graph1[i+2][1]=2;}}
    if(max_flow(0,1)!=n)return(cout<<"Impossible\n",0);
    for(int i=2;i<n+2;i++)if(!VIS[i]){memset(vis,0,sizeof vis);DFS(i,-1);p.clear();}
    cout<<sz(ans)<<endl;
    for(int i=0;i<sz(ans);++i){cout<<sz(ans[i])<<" ";lop(j,0,sz(ans[i]))cout<<ans[i][j]-1<<" ";cout<<endl;}
}