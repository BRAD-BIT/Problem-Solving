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
const int MAX = 200 + 7;
struct EDGE
{
    ll indx, weight; EDGE(int i, ll w) :indx(i), weight(w){};
    bool operator<(EDGE e)const{ return e.weight < weight; }
};
vvii G[2]; int n, d;
ll Dijkstra(int s,int cost,int limit,int x)
{
    priority_queue<EDGE>q; q.push(EDGE(s, 0));
    vi vis(n, 0); vll dis(n,OO); dis[s] = 0;
    while (!q.empty())
    {
        EDGE cur = q.top(); q.pop();
        if (vis[cur.indx])continue;
        vis[cur.indx] = 1;
        lop(i, 0, sz(G[x][cur.indx]))
        {
            ii child = G[x][cur.indx][i];
            if (dis[child.first]>dis[cur.indx] + child.second)
            {
                dis[child.first] = dis[cur.indx] + child.second;
                q.push(EDGE(child.first, dis[child.first]));
            }
    }
    }
    if (!x)
    lop(i, 0, n)
    {if (i != s&&dis[i] <= limit)G[1][s].push_back(ii(i, cost));}
    else
        return dis[d];
}
int main()
{
    int m, s; cin >> n >> m >> s >> d; s--, d--;
    G[0].resize(n), G[1].resize(n);
    lop(i, 0, m)
    {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        G[0][a].push_back(ii(b, c)); G[0][b].push_back(ii(a, c));
    }
    lop(i, 0, n)
    {
        int a, b; cin >> a >> b;
        Dijkstra(i, b, a, 0);
    }
    ll ans = Dijkstra(s, -1, -1, 1);
    if (ans < OO)cout << ans << endl; else cout << -1 << endl;
}