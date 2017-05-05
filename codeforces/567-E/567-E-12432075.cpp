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
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#include<string>
#include<cstdio>
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 1e5 + 7;
struct EDGE
{
    ll indx, weight; EDGE(int i, ll w) :indx(i), weight(w){};
    bool operator<(EDGE e)const{ return e.weight < weight; }
};
struct edge{ int a, b, c; edge(int aa = 0, int bb = 0, int cc= 0) :a(aa), b(bb), c(cc){} };
vvii G[2]; vvi G2; vll dis[2]; int n, cnt = 0; vector<edge>ed; int used[MAX] = { 0 };
int dfs_num[MAX], dfs_low[MAX]; map<ii, int>mp; map<ii, int>mp2;
void Dijkstra(int s,int x)
{
    priority_queue<EDGE>q; q.push(EDGE(s, 0));
    vi vis(n, 0); dis[x].resize(n, OO); dis[x][s] = 0;
    while (!q.empty())
    {
        EDGE cur = q.top(); q.pop();
        if (vis[cur.indx])continue;
        vis[cur.indx] = 1;
        lop(i, 0, sz(G[x][cur.indx]))
        {
            ii child = G[x][cur.indx][i];
            if (dis[x][child.first]>dis[x][cur.indx] + child.second)
            {
                dis[x][child.first] = dis[x][cur.indx] + child.second;
                q.push(EDGE(child.first, dis[x][child.first]));
            }
        }
    }
}
void tarjan(int v, int p)
{
    dfs_num[v] = dfs_low[v] = ++cnt;
    for (int i = 0; i < G2[v].size(); ++i)
    {
        int child = G2[v][i];
        if (dfs_num[child] == -1)
        {
            tarjan(child, v);
            if (dfs_low[child] > dfs_num[v])
            {
                if (!(mp2[ii(v,child)]>1))
                mp[ii(v, child)] = 1;
                //cout << v << "--Bridge--" << child << endl;
            }
            dfs_low[v] = min(dfs_low[v], dfs_low[child]);
        }
        else if (child != p) dfs_low[v] = min(dfs_low[v], dfs_num[child]);
    }
}
int main()
{
    int m, s, d; cin >> n >> m >> s >> d; s--, d--;
    G[0].resize(n), G[1].resize(n); G2.resize(n);
    lop(i, 0, m)
    {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        G[0][a].push_back(ii(b, c));
        G[1][b].push_back(ii(a, c));
        ed.push_back(edge(a, b, c));
    }
    Dijkstra(s, 0);
    Dijkstra(d, 1);
    lop(i, 0, m)
        if (dis[0][ed[i].a] + dis[1][ed[i].b] + ed[i].c == dis[0][d])
            G2[ed[i].a].push_back(ed[i].b), G2[ed[i].b].push_back(ed[i].a), mp2[ii(ed[i].a, ed[i].b)]++;
    memset(dfs_num, -1, sizeof dfs_num);
    tarjan(s, -1);
    lop(i, 0, m)
    {
        ll path = dis[0][ed[i].a] + dis[1][ed[i].b] + ed[i].c;
        if (path > dis[0][d]){
            if (path - dis[0][d] + 1 < ed[i].c)cout << "CAN " << path - dis[0][d] + 1 << endl;
            else cout << "NO\n";}
        else
        {
            if (mp[ii(ed[i].a, ed[i].b)])cout << "YES\n";
            else
                if (ed[i].c > 1)cout << "CAN 1\n"; else cout << "NO\n";
        }
    }
}