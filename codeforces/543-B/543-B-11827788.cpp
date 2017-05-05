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
const int MAX = 3010;
vector<vector<int>>graph; int vis[MAX]; int len[MAX][MAX];
void BFS(int i)
{
    queue<int>q; q.push(i); len[i][i] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop(); int dep = len[i][cur];
        for (int k = 0; k < graph[cur].size(); ++k)
        {
            int child = graph[cur][k];
            if (len[i][child] == oo)len[i][child] = dep + 1, q.push(child);
        }
    }
}
int main()
{
    int n, m; cin >> n >> m; graph.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int s1, s2, d1, d2, l1, l2;
    cin >> s1 >> d1 >> l1 >> s2 >> d2 >> l2; --s1, --s2, --d1, --d2;
    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)len[i][j] = oo;
    for (int i = 0; i < n; ++i)BFS(i);
    if (len[s1][d1] > l1 || len[s2][d2] > l2){ cout << "-1\n"; return 0; }
    int ans = m - len[s1][d1] - len[s2][d2];
    for (int k = 0; k < 2; k++)
    {
        swap(s1, d1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (len[s1][i] + len[i][j] + len[j][d1] <= l1&&len[s2][i] + len[i][j] + len[j][d2] <= l2)
                    ans = max(ans, m - (len[s1][i] + len[j][d1] + len[s2][i] + len[i][j] + len[j][d2]));
    }
    cout << ans << endl;
}