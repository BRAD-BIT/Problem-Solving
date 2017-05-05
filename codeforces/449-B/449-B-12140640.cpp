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
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 }; 
struct Edge
{
    ll weight, indx; Edge(int w,int i) :indx(i), weight(w){}
    bool operator<(const Edge& e)const{ return e.weight < weight; }
};
struct edge{ int a, b, c; edge(int A, int B,int C) :a(A), b(B),c(C){} };
vi dis, vis, use; vector<vector<edge>>G;
int dijkstra()
{
    priority_queue<Edge>p; dis[0] = 0;
    p.push(Edge(0, 0)); int ans = 0;
    while (!p.empty())
    {
        Edge cur = p.top(); p.pop();
        if (vis[cur.indx])continue;
        vis[cur.indx] = 1;
        for (int i = 0; i < G[cur.indx].size(); ++i)
        {
            edge child = G[cur.indx][i];
            if (dis[child.a] > dis[cur.indx] + child.b || (dis[child.a] == dis[cur.indx] + child.b&&child.c==1))
            {
                dis[child.a] = dis[cur.indx] + child.b;
                if(child.c == 2)  
                    ans++,ans-=use[child.a],use[child.a] = 1;
                else  ans -= use[child.a], use[child.a] = 0;
                p.push(Edge(dis[child.a], child.a));
            }
        }
    }
    return ans;
}
int main()
{
    int n, m, k; sc(n), sc(m), sc(k);
    G.resize(n); dis.resize(n, oo); vis.resize(n, 0); use.resize(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; sc(a), sc(b), sc(c); --a, --b;
        G[a].push_back(edge(b, c, 1)) , G[b].push_back(edge(a, c, 1));
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c; sc(a), sc(c); --a, b=0;
        G[a].push_back(edge(b, c, 1)), G[b].push_back(edge(a, c, 2));
    }
    pr1(k-dijkstra());
}