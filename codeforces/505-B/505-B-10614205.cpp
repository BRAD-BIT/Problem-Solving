#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
map<pair<int, int>,int>MP;
vector<vector<vector<int>>>graphs;
int visited[107] = { 0 };
int counter = 0; bool test = false;
void DFS(int from, int to,int x)
{
    visited[from] = counter;
    if (from == to){ test = true; return; }
    for (int i = 0; i < graphs[x][from].size(); i++)
    {
        int child = graphs[x][from][i];
        if (visited[child] != counter)DFS(child, to, x);
    }
}
struct edge{ int a, b, c; };
int main()
{
    int n, m, q; cin >> n >> m; edge o[107];int Max = 0; int coleer[114] = { 0 };
    for (int i = 0; i < m; i++)
    {
        cin >> o[i].a >> o[i].b >> o[i].c; if (Max < o[i].c)Max = o[i].c; coleer[o[i].c - 1]++;
    }
    graphs = vector<vector<vector<int>>>(Max);
    for (int i = 0; i < Max; i++)
    {
        graphs[i] = vector<vector<int>>(n);
    }
    for (int i = 0; i < m; i++)
    {
        graphs[o[i].c - 1][o[i].a - 1].push_back(o[i].b - 1);
        graphs[o[i].c - 1][o[i].b - 1].push_back(o[i].a - 1);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v, ans = 0; cin >> u >> v;
        for (int j = 0; j < Max; j++)
        {
            if (coleer[j] != 0)
            {
                test = false;
                counter++;
                DFS(u - 1, v - 1, j);
                if (test)ans++;
            }
        }
        cout << ans << endl;
    }
}