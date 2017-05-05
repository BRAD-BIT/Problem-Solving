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
#define pr2(n)     printf("%d " ,n)
#define pr1(n)     printf("%d\n",n)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
bool comp(ii a, ii b){ return a.first < b.first; }
vvi graph; vii dis; vi remain;
int main()
{
    int n, k; cin >> n >> k; dis.resize(n); ll M = 0; remain.resize(n, k);
    for (int i = 0; i < n; i++)sc(dis[i].first), dis[i].second = i + 1, M = max(M, dis[i].first);
    sort(all(dis));
    if (dis[0].first == dis[1].first || dis[0].first != 0){ pr1(-1); return 0; }
    vii ANS; int edge = 0;
    graph.resize(M+1);
    for (int i = 0; i < n; i++)
    {
        graph[dis[i].first].push_back(dis[i].second);
    }
    for (int i = 0; i < M; i++)
    {
        int start = 0; int v;
        for (int j = 0; j < graph[i].size(); j++)
        {
            for (v = start; v < graph[i + 1].size(); v++)
            {
                if (remain[graph[i][j] - 1] != 0 && remain[graph[i + 1][v] - 1] != 0)
                {
                    ANS.push_back(make_pair(graph[i][j], graph[i + 1][v])); edge++;
                    remain[graph[i][j] - 1]--, remain[graph[i + 1][v] - 1]--;
                }
                else { v--; break; }
            }
            start = v+1;
        }
    }
    if (edge != n - 1){ pr1(-1); return 0; }
    pr1(n - 1);
    for (int i = 0; i < n - 1; i++)pr2(ANS[i].first), pr1(ANS[i].second);
}