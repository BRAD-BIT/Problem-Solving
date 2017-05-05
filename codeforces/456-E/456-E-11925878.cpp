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
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define  oo  1e9
using namespace std;
const int MAX = 3 * 100000;
vector<vector<int>>graph; int vis[MAX];
class unionFind
{
public:
    vector<int> rank, parent, diamter, vis;
    unionFind(int n)
    {
        rank.resize(n); parent.resize(n); diamter.resize(n, 0); vis.resize(n, 0);
        for (int i = 0; i < n; ++i)rank[i] = 0, parent[i] = i;
    }
    int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
    bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
    void union_set(int i, int j) {
        if (!isSameSet(i, j))
        {
            int x = find_set(i), y = find_set(j);
            if (rank[x] > rank[y])
            {
                parent[y] = x;
                diamter[x] = max(max(diamter[x], diamter[y]), int(ceil(ceil(diamter[x] / 2.000) + ceil(diamter[y] / 2.000)) + 1));
            }
            else
            {
                parent[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
                diamter[y] = max(max(diamter[x], diamter[y]), int(ceil(ceil(diamter[x] / 2.000) + ceil(diamter[y] / 2.000)) + 1));
            }
        }
    }
};
void DFS(int depth,int &MAX2,int &MAX_node, int node,int from)
{
    if (MAX2 < depth)MAX2 = depth, MAX_node = node;
    for (int i = 0; i < graph[node].size(); ++i)
    {
        int child = graph[node][i];
        if(child!=from)DFS(depth + 1, MAX2, MAX_node, child,node);
    }
}
int main()
{
    //R_W;
    int n, m, q; cin >> n >> m >> q; graph.resize(n); unionFind UN(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b; scanf("%d%d", &a, &b); --a, --b; graph[a].push_back(b); graph[b].push_back(a);
        UN.union_set(a, b);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!vis[UN.find_set(i)])
        {
            vis[UN.find_set(i)] = 1;
            int M = i, N = 0;
            DFS(0, N, M, i, -1); N = 0;
            DFS(0, N, M, M, -1);
            UN.diamter[UN.find_set(i)] = N;
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int type; cin >> type;
        if (type == 2)
        {
            int x, y; scanf("%d%d", &x, &y);
            UN.union_set(--x, --y);
        }
        else
        {
            int x;
            scanf("%d", &x); --x;
            printf("%d\n", UN.diamter[UN.find_set(x)]);
        }
    }
}