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
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
vvi graph; vi color;
int main()
{
    int n, m; cin >> n >> m; color.resize(n); int s = 0; map<ii, int>mp;
    for (int i = 0; i < n; i++) { scanf("%d", &color[i]); s=max(s,color[i]); }
    graph.resize(s);
    for (int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);a = color[--a]-1, b = color[--b]-1;
        if (a != b&&!mp[make_pair(min(a, b), max(a, b))])
        {
            graph[a].push_back(b), graph[b].push_back(a); mp[make_pair(min(a, b), max(a, b))] = 1;
        }
    }
    ii MAX(make_pair(0,oo));
    for (int i = 0; i < n; i++)
    {
        ll a = color[i]-1;
        if (graph[a].size() > MAX.first)MAX.first = graph[a].size(), MAX.second = ++a;
        else
            if (graph[a].size() == MAX.first)MAX.second = min(++a, MAX.second);
    }
    printf("%d\n", MAX.second);
}