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
vector<vector<int>>graph;
int visited[405] = { 0 };
bool test = false; int counter = 0;
void DFS(int from,int to)
{
    visited[from] = counter;
    if (from == to){ test = true; return; }
    for (int i = 0; i < graph[from].size(); i++)
    {
        int child = graph[from][i];
        if (visited[child]!=counter)DFS(child, to);
    }
}
int main()
{
    int n, m; string sn, sm; cin >> n >> m >> sn >> sm;
    graph = vector<vector<int>>(n*m); int x = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sn[i] == '>'&&j + 1 < m)graph[x].push_back(x + 1);
            if (sn[i] == '<'&&j - 1 >= 0)graph[x].push_back(x - 1);
            if (sm[j] == '^'&&x - m >= 0)graph[x].push_back(x - m);
            if (sm[j] == 'v'&&x + m < n*m)graph[x].push_back(x + m);
            x++;
        }
    }
    for (int i = 0; i < n*m; i++)
    {
        for (int j = 0; j < n*m; j++)
        {
            if (i != j)
            {
                counter++;
                test = false;
                DFS(i, j);
                if (!test){ cout << "NO" << endl; return 0; }
            }
        }
    }
        cout << "YES" << endl;
}