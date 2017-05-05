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
int visited[2500][2500];
bool cycle = false;
void DFS(int node1,int node2, int x)
{
    visited[x][node1] = DFS_GRAY;
    for (int i = 0; i < graph[node1].size(); i++)
    {
        int child = graph[node1][i];
        if (visited[x][child] == DFS_GRAY &&child != node2)cycle = true;
        if (visited[x][child] == DFS_WHITE)DFS(child,node1,x);
    }
    visited[x][node1] = DFS_BLACK;
}
int main()
{
    int n, m; char a[50][50]; cin >> n >> m; int x = 0;
    for (int i = 0; i < n*m; i++)
    for (int j = 0; j < n*m; j++)
    {
        visited[i][j] = 0;
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        cin >> a[i][j];
    }
    graph = vector<vector<int>>(n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j + 1 < m&&a[i][j] == a[i][j + 1])graph[x].push_back(x + 1);
            if (j - 1 >= 0 && a[i][j] == a[i][j - 1])graph[x].push_back(x - 1);
            if (i + 1 < n&&a[i][j] == a[i + 1][j])graph[x].push_back(x + m);
            if (i - 1 >= 0 && a[i][j] == a[i - 1][j])graph[x].push_back(x - m);
            x++;
        }
    }
    for (int i = 0; i < n*m; i++)
    {
        DFS(i,-10000,i);
        if (cycle){ cout << "Yes" << endl; return 0; }
    }
    cout << "No" << endl;
}