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
#define ii         pair<int,int>
#define vii        vector<ii>
#define vi         vector<int>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
vi dfs_num; vvi graph[2]; vi s; vi price; pair<int, int>mn; pair<ll, ll>ANS = make_pair(0, 1);
void Kosaraju(int node, int pass)
{
    dfs_num[node] = 1;
    for (int i = 0; i<graph[pass][node].size(); ++i)
    {
        int child = graph[pass][node][i];
        if (dfs_num[child] == DFS_WHITE)Kosaraju(child, pass);
    }
    s.push_back(node);
    if (pass)
    {
        if (price[node] < mn.first)mn.first = price[node], mn.second = 1;
        else
            if (price[node] == mn.first)mn.second++;
    }
}
int SCC(int n)
{
    int cnt = 0;
    dfs_num.resize(n, DFS_WHITE);
    for (int i = 0; i < n; i++)if (dfs_num[i] == DFS_WHITE)Kosaraju(i, 0);
    dfs_num.assign(n, DFS_WHITE);
    for (int i = n - 1; i >= 0; i--)if (dfs_num[s[i]] == DFS_WHITE)
        mn = make_pair(oo, 0), cnt++, Kosaraju(s[i], 1),
        ANS.first += mn.first, ANS.second *= mn.second % 1000000007, mn.second %= 1000000007;
    return cnt;
}
int main()
{
    int n, m; cin >> n; graph[0].resize(n); graph[1].resize(n); price.resize(n);
    for (int i = 0; i < n; i++)cin >> price[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; --a, --b;
        graph[0][a].push_back(b), graph[1][b].push_back(a);
    }
    SCC(n); cout << ANS.first << " " << ANS.second % 1000000007 << endl;
}