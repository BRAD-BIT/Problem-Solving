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
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int ans[100000];
vector<vector<int>>graph;
void dfs(int node,int prev)
{
    ans[node] = prev;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        if (!ans[child])dfs(child, node+1);
    }
}
int main()
{
    int n, r1, r2, sum = 0; cin >> n >> r1 >> r2; graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x; sum++;
        if (i != r1-1)
        {graph[i].push_back(--x); graph[x].push_back(i);}
        else
        {graph[i + 1].push_back(--x); graph[x].push_back(i+1);i++;}
        if (sum == n - 1)break;
    }
    memset(ans, 0, sizeof ans);
    dfs(r2 - 1, -1);
    for (int i = 0; i < n; i++)if (ans[i] != -1)cout << ans[i] << " "; cout << endl;
}