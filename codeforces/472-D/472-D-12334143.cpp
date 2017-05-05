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
#define lop(i,n)   for(int i=0;i<n;++i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define ld         long double
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 2000 + 7;
ll Grid[MAX][MAX]; vector<pair<ii, int>> edges; vvii graph; ll dis[MAX][MAX];
struct edge
{
    ll idx, weight; edge(ll i, ll w) :idx(i), weight(w){}
    bool operator<(edge e)const{ return e.weight < weight; }
};
bool comp(pair<ii, int>a, pair<ii, int>b){ return a.second < b.second; }
class unionFind
{
    vector<int> rank, parent;
public:
    unionFind(int n)
    {
        rank.resize(n); parent.resize(n);
        for (int i = 0; i < n; ++i)rank[i] = 0, parent[i] = i;
    }
    int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
    bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
    bool union_set(int i, int j) {
        if (!isSameSet(i, j))
        {
            int x = find_set(i), y = find_set(j); if (rank[x] > rank[y]) parent[y] = x;
            else { parent[x] = y; if (rank[x] == rank[y]) rank[y]++; }
            return 1;
        }
        return 0;
    }
};
void dijkstra(int i)
{
    priority_queue<edge>q; dis[i][i] = 0; q.push(edge(i, 0)); int vis[MAX] = { 0 };
    while (!q.empty())
    {
        edge cur = q.top(); q.pop();
        if (vis[cur.idx])continue;
        vis[cur.idx] = 1;
        lop(j, sz(graph[cur.idx]))
        {
            ii child = graph[cur.idx][j];
            if (dis[i][child.first] > dis[i][cur.idx] + child.second)
                dis[i][child.first] = dis[i][cur.idx] + child.second;
            q.push(edge(child.first, dis[i][child.first]));
        }
    }
}
int main()
{
    int n; sc(n); unionFind UN(n); graph.resize(n);
    lop(i, n)lop(j, n){ sc(Grid[i][j]); dis[i][j] = OO; }
    lop(i, n)lop(j, n)
    {
        if (j >= i)
        {
            if ((i == j&&Grid[i][j] != 0) || (Grid[i][j] != Grid[j][i])||(i!=j&&Grid[i][j]==0))return(cout << "NO\n", 0);
            if (i != j)
            {
                edges.push_back(pair<ii, int>(ii(i, j),Grid[i][j]));
            }
        }
    }
    sort(all(edges), comp);
    lop(i, edges.size())
    {
        if (UN.union_set(edges[i].first.first, edges[i].first.second))
        {
            graph[edges[i].first.first].push_back(ii(edges[i].first.second, edges[i].second));
            graph[edges[i].first.second].push_back(ii(edges[i].first.first, edges[i].second));
        }
    }
    lop(i, n)dijkstra(i);
    lop(i, n)lop(j, n)if (Grid[i][j] != dis[i][j])return(cout << "NO\n", 0);
    cout << "YES\n";
}