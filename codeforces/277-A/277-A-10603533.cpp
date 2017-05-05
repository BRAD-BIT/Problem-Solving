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
int visited[101] = { 0 };
void DFS(int node)
{
    visited[node - 1] = 1;
    for (int i = 0; i < graph[node - 1].size(); i++)
    {
        int child = graph[node - 1][i];
        if (!visited[child])DFS(child + 1);
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
            DFS(i + 1);
        }
    }
    return cnt;
}
int main()
{
    int n, m; cin >> n >> m;
    graph = vector<vector<int>>(n);
    vector<vector<int>>language(m);
    int a[100][101];
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        if (a[i][0] == 0)zero++;
        for (int j = 1; j <= a[i][0]; j++)
        {
            cin >> a[i][j]; language[a[i][j] - 1].push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= a[i][0]; j++)
        {
            for (int z = 0; z < language[a[i][j] - 1].size(); z++)
            {
                if (language[a[i][j] - 1][z] != i)
                    graph[i].push_back(language[a[i][j] - 1][z]);
            }
        }
    }
    if (zero == n)cout << zero; else cout << ConnectedComponenetsCnt() - 1;
}