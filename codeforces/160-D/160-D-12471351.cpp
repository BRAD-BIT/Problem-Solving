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
int const MAX = 1e5 + 7;
struct edge{ int a, b, weight, inx; };
vector<edge>G; vector<string>ANS;
map<int, int>mp1; int dfs_num[MAX], dfs_low[MAX]; int cnt = 0; vvii component; map<ii, int>multi_edge;
bool comp(edge a, edge b)
{
    if (a.weight != b.weight)return a.weight < b.weight;
    return ANS[a.inx] < ANS[b.inx];
}
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
void tarjan(int v, int p)
{
    dfs_num[v] = dfs_low[v] = ++cnt;
    for (int i = 0; i < component[v].size(); ++i)
    {
        ii child = component[v][i];
        if (dfs_num[child.first] == -1)
        {
            tarjan(child.first, v);
            if (dfs_low[child.first] > dfs_num[v])
            {
                if (multi_edge[ii(child.first,v)]==1)
                ANS[child.second] = "any\n";
                // <<child.first<< " bridge  " << v << endl;
            }
            dfs_low[v] = min(dfs_low[v], dfs_low[child.first]);
        }
        else if (child.first != p) dfs_low[v] = min(dfs_low[v], dfs_num[child.first]);
    }
}
int main()
{
    //R_W;
    int n, m; cin >> n >> m; G.resize(m); ANS.resize(m, "at least one\n");
    unionFind UN(n);
    for (int i = 0; i < m; ++i)
        cin >> G[i].a >> G[i].b >> G[i].weight, G[i].inx = i, mp1[G[i].weight]++, G[i].a--, G[i].b--;
    sort(G.begin(), G.end(), comp);
    for (int i = 0; i < m; ++i)
    {
        int k = mp1[G[i].weight]; map<ii, int>mp2; map<int, int>mp;  int h = 1;
        lop(u, i, i + k)
        {
            int a = UN.find_set(G[u].a), b = UN.find_set(G[u].b);
            if (a != b)
            {
                if (mp[a] == 0)mp[a] = h++;
                if (mp[b] == 0)mp[b] = h++;
            }
            else ANS[G[u].inx] = "none\n";
        }
        component.resize(h - 1); lop(i, 0, h - 1)dfs_num[i] = -1;
        lop(u, i, i + k)
        {
            int a = UN.find_set(G[u].a), b = UN.find_set(G[u].b);
            if (a != b)
            {
                component[mp[a]-1].push_back(ii(mp[b]-1, G[u].inx)),
                component[mp[b]-1].push_back(ii(mp[a]-1, G[u].inx));
                multi_edge[ii(mp[a] - 1, mp[b] - 1)]++;
                multi_edge[ii(mp[b] - 1, mp[a] - 1)]++;
            }
        }
        lop(i, 0, h-1)if (dfs_num[i] == -1)tarjan(i, -1);
        lop(u, i, i + k)
        {
            UN.union_set(G[u].a, G[u].b);
        }
        component.clear();
        multi_edge.clear();
        i += (k-1);
    }
    for (int i = 0; i < m; i++)cout << ANS[i];
}