#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<vector<int>>graph;
int len[100000];
int shotest_path(int start, int to)
{
    queue<int>q; len[start] = 0; q.push(start);
    ll cur, dep;
    while (!q.empty())
    {
        cur = q.front(); q.pop(); dep = len[cur];
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int child = graph[cur][i];
            if (len[child] == -1){ q.push(child); len[child] = dep+1; if (child == to)return dep + 1; }
        }
    }
}
int main()
{
    //R_W;
    int a, b, c; cin >> a >> b; c = a;
    if (b < a){ cout << a - b; return 0; }
    graph.resize(2 * b);
    memset(len, -1, 100000);
    for (int i = 1; i < 2 * b; i++)
    {
        if (i * 2 < 2 * b)graph[i].push_back(i * 2);
        if (i - 1 != 0)graph[i].push_back(i - 1);
    }
    ll ans = shotest_path(a, b);
    cout << endl << ans << endl;
}