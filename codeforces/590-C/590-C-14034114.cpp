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
int const MAX = 1000 + 7;
int const MOD = 1000000007;
ll dis[3][MAX][MAX],vis[3][MAX][MAX];
char grid[MAX][MAX];
vii heads[3];
int n,m;
struct edge
{
    int r,c,weight;
    edge(int _r,int _c,int w):r(_r),c(_c),weight(w){}
    bool operator<(const edge&e)const{ return weight>e.weight; }
};
void Dijkstra(int i)
{
    priority_queue<edge>q;
    lop(j,0,sz(heads[i]))
    q.push(edge(heads[i][j].first,heads[i][j].second,0))
    ,dis[i][heads[i][j].first][heads[i][j].second]=0;
    while(!q.empty())
    {
        edge cur=q.top();q.pop();
        if(vis[i][cur.r][cur.c])continue;
        vis[i][cur.r][cur.c]=1;
        lop(j,0,4)
        {
            int X=cur.r+dr[j],Y=cur.c+dc[j];
            if(X>=n||X==-1||Y>=m||Y==-1)continue;
            if(grid[X][Y]=='#')continue;
            int road=grid[X][Y]=='.';
            if(dis[i][X][Y]>dis[i][cur.r][cur.c]+road)
            {
                dis[i][X][Y]=dis[i][cur.r][cur.c]+road;
                q.push(edge(X,Y,dis[i][X][Y]));
            }
        }
    }
}
int main ()
{
    cin>>n>>m;
    lop(i,0,n)lop(j,0,m){
    cin>>grid[i][j];dis[0][i][j]=dis[1][i][j]=dis[2][i][j]=oo;
    if(grid[i][j]!='#'||grid[i][j]!='.')heads[grid[i][j]-'1'].push_back(ii(i,j));
    }
    Dijkstra(0);Dijkstra(1);Dijkstra(2);
    ll ANS=oo;
    lop(i,0,n)lop(j,0,m)ANS=min(ANS,dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-2*(grid[i][j]=='.'));
    (ANS==oo)?printf("-1\n"):printf("%lld\n",ANS);
}