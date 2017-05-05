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
#define R_(s)        freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI 3.14159265358979323846
#define ll long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<vector<int>>graph; int visited[107] = { 0 };
void DFS(int node)
{
    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        if (!visited[child])DFS(child);
    }
}
int ConnectedComponenetsCnt()
{
    int cnt = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}
int main()
{
    //R_W;
    int n, m; cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    int x = ConnectedComponenetsCnt(); ll ans = pow(2.00000, n - x);
    cout << ans << endl;
}