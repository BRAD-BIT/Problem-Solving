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
#define oo  1000
#define OO  1e18
#define EPS 1e-9
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
int vis[MAX],prv[MAX],graph1[MAX][MAX],arr[MAX],res[MAX][MAX];
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
int a[MAX],b[MAX];
int main()
{
    int n,m,sum=0;cin>>n>>m;
    graph2.resize(2*n+2);
    lop(i,0,n){cin>>a[i];sum+=a[i];}
    lop(i,0,n){cin>>b[i];sum-=b[i];}
    if(sum!=0)return(cout<<"NO\n",0);
    lop(i,0,m)
    {
        int x,y;cin>>x>>y;
        graph1[x+1][y+n+1]=graph1[y+1][x+n+1]=oo;
        graph2[x+1].push_back(y+n+1),graph2[y+1].push_back(x+n+1);
        graph2[y+n+1].push_back(x+1),graph2[x+n+1].push_back(y+1);
        
    }
    lop(i,0,n)
    {
        sum+=a[i];
        graph2[i+2].push_back(i+n+2),graph2[i+n+2].push_back(i+2);
        graph1[i+2][i+n+2]=oo;
        graph2[0].push_back(i+2),graph2[i+2].push_back(0);
        graph2[1].push_back(i+n+2),graph2[i+n+2].push_back(1);
        graph1[0][i+2]=a[i],graph1[i+n+2][1]=b[i];
    }
    if(max_flow(0,1)!=sum)return(cout<<"NO\n",0);
    cout<<"YES\n";
    lop(i,2,n+2)
    lop(j,n+2,2*n+2)
    {
        if(graph1[i][j]==0)continue;
        res[i-2][j-2-n]+=graph1[j][i];
    }
    lop(i,0,n){lop(j,0,n)cout<<res[i][j]<< " ";cout<<endl;}
}