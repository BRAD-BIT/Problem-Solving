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
#define sz(v)      (ll)v.size()
#define ii         pair<int,int>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
vvii graph; int vis[100008]; int dis[100008]; int dis2[100008];
int DFS(int node,int num,int change)
{
    vis[node] = 1; int ans = 0; if (change)dis[node] = num;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i].first;
        if (!vis[child])if (DFS(child, num + graph[node][i].second - 1, graph[node][i].second == 2))ans = 1, dis[node] = -1;
    }
    return dis[node] != -1 || ans;
}
int main()
{
    int n; cin >> n; graph.resize(n);
    for (int i = 0; i < n-1; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b;
        graph[a].push_back(make_pair(b, c)), graph[b].push_back(make_pair(a, c));
    }
    memset(vis, 0, sizeof vis);
    memset(dis, -1, sizeof dis);
    DFS(0, 0, 1); 
    int sum = 0; vi ans;
    for (int i = 1; i < n; i++)if (dis[i] != -1)++sum, ans.push_back(i + 1);
    printf("%d\n", sum); for (int i = 0; i < ans.size(); i++)printf("%d ", ans[i]);
}