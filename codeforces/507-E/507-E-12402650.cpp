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
const int MAX = 4 * 1e5 + 7;
struct EDGE
{
    int indx, weight, z; EDGE(int i, int w, int x) :indx(i), weight(w), z(x){};
    bool operator<(EDGE e)const{ if (e.weight == weight)return e.z > z; return e.weight < weight; }
};
struct ed{ int a, b, z; ed(int aa = 0, int bb = 0, int zz = 0) :a(aa), b(bb), z(zz){}; };
vvii G; vi dis; vi pre; map<ii, int>used; int n; ed edges[MAX]; vi dis2;
void Dijkstra()
{
    priority_queue<EDGE>q; q.push(EDGE(0, 0, 0)); vi vis(n, 0); dis.resize(n, oo); pre.resize(n, -1); dis[0] = 0; dis2.resize(n, 0);
    while (!q.empty())
    {
        EDGE cur = q.top(); q.pop();
        if (vis[cur.indx])continue;
        vis[cur.indx] = 1;
        lop(i, 0, sz(G[cur.indx]))
        {
            ii child = G[cur.indx][i];
            if (dis[child.first]>dis[cur.indx] + 1)
            {
                dis[child.first] = dis[cur.indx] + 1;
                dis2[child.first] = cur.z + child.second;
                pre[child.first] = cur.indx;
                q.push(EDGE(child.first, dis[child.first], dis2[child.first]));
            }
            else
            if (dis[child.first] == dis[cur.indx] + 1 && dis2[child.first]<cur.z+child.second)
            {
            pre[child.first] = cur.indx;
            dis2[child.first] += child.second;
            q.push(EDGE(child.first, dis[child.first], dis2[child.first]));
            }
        }
    }
    vi path;
    int u = n - 1;
    path.push_back(u);
    while (pre[u] != 0)
    {
        u = pre[u];
        path.push_back(u);
    }
    path.push_back(0);
    reverse(all(path));
    lop(i, 0, sz(path) - 1)
    {
        used[ii(min(path[i], path[i + 1]), max(path[i], path[i + 1]))] = 1;
    }
}
int main()
{
    int m; sc(n), sc(m); G.resize(n);
    lop(i, 0, m)
    {
        int a, b, z; sc(a), sc(b), sc(z); --a, --b;
        G[a].push_back(ii(b, z));   G[b].push_back(ii(a, z));
        edges[i].a = min(a, b); edges[i].b = max(a, b); edges[i].z = z;
    }
    Dijkstra();
    vector<ed> ans;
    lop(i, 0, m)
    {
        if (used[ii(edges[i].a, edges[i].b)])
        {
            if (edges[i].z == 0)ans.push_back(ed(edges[i].a, edges[i].b, 1));
        }
        else
        {
            if (edges[i].z)ans.push_back(ed(edges[i].a, edges[i].b, 0));
        }
    }
    pr1(sz(ans));
    lop(i, 0, sz(ans))pr2(ans[i].a + 1),pr2(ans[i].b + 1),pr1(ans[i].z);
}