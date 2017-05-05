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
const int MAX = 2*100000+1;
vector<vector<int>>graph; int len[MAX]; int prv[MAX];
void BFS(int start)
{
    queue<int>q; q.push(start); len[start] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop(); int dep = len[cur];
        for (int k = 0; k < graph[cur].size(); ++k)
        {
            int child = graph[cur][k];
            if (len[child] == oo)len[child] = dep + 1, q.push(child), prv[child] = cur;
        }
    }
}
int main()
{
    int n, k; cin >> n >> k; string s1, s2; cin >> s1 >> s2; graph.resize(2*n + 1);
    for (int i = 0; i < MAX; i++)len[i] = oo;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '-')
        {
            if (i + 1 == n||i+k>=n)graph[i].push_back(2 * n);
            if (i + 1 < n)if (s1[i+1] == '-')graph[i].push_back(i + 1);
            if (i - 1 >= 0)if (s1[i - 1] == '-')graph[i].push_back(i - 1);
            if (i + k < n)if (s2[i + k] == '-')graph[i].push_back(i+n + k);
        }
        if (s2[i] == '-')
        {
            if (i + 1 == n || i + k >= n)graph[n+i].push_back(2 * n);
            if (i + 1 < n)if (s2[i + 1] == '-')graph[n+i].push_back(n+i + 1);
            if (i - 1 >= 0)if (s2[i - 1] == '-')graph[i+n].push_back(n+i-1);
            if (i + k < n)if (s1[i + k] == '-')graph[i+n].push_back(i + k);
        }
    }
    BFS(0);
    if (len[2 * n] == oo){ cout << "NO\n"; return 0; }
    vector<int>path;
    path.push_back(2 * n); int j = 2 * n;
    while (prv[j] != 0)
    {
        path.push_back(prv[j]); j = prv[j];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        int cur_level;
        if (path[i] >= n)cur_level = path[i] - n; else cur_level = path[i];
        if (cur_level < i){ cout << "NO\n"; return 0; }
    }
    cout << "YES\n";
}