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
#include<ctime>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
vector<vector<int>>graph;
int a; int dis[3007] = { 0 };
int visited[3007] = { 0 };
int counter1 = -1, counter2 = 0, counter3 = 1;
void DFS(int node1, int node2, int node3)
{
    visited[node1] = counter1;
    for (int i = 0; i < graph[node1].size(); i++)
    {
        int child = graph[node1][i];
        if (visited[child] == counter1 &&child != node2){ if (child == node3){ a = node3; dis[node3] = 1; } }
        if (visited[child] == counter2)DFS(child, node1, node3);
    }
    visited[node1] = counter3;
}
int num_edges = 0; int counter = 0;
void DFS2(int from, int to, int pass)
{
    visited[from] = counter;
    if (dis[from] == 1){ pass = 0; }
    if (from == to){ num_edges = pass; return; }
    for (int i = 0; i < graph[from].size(); i++)
    {
        int child = graph[from][i];
        if (visited[child] != counter)DFS2(child, to, pass + 1);
    }
}
int main()
{
    int n; cin >> n;
    graph = vector<vector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; i++)
    {
        DFS(i, -100, i); counter1++; counter2++; counter3++;
    }
    memset(visited, 0, 3007);
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == 0)
        {
            counter++; DFS2(a, i, 0); cout << num_edges << " ";
        }
        else cout << 0 << " ";
    }cout << endl;
}