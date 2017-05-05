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
vector<int>value; 
vector<int>index;
int a[307];
int visited[307] = { 0 };
void DFS(int node)
{
    value.push_back(a[node]);
    index.push_back(node);
    visited[node] = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        if (!visited[child])DFS(child);
    }
}
void sort()
{
    for (int i = 0; i < graph.size();i++)
    {
        value.clear();
        index.clear();
        if (!visited[i])DFS(i);
        sort(value.begin(), value.end());
        sort(index.begin(), index.end());
        for (int j = 0; j < value.size(); j++)
        {
            a[index[j]] = value[j];
        }
    }
}
int main()
{
    int n; cin >> n;
    graph = vector<vector<int>>(n);
    char b[307][307];
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> b[i][j];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == '1')graph[i].push_back(j);
        }
    }
    sort();
    for (int i = 0; i < n; i++)cout << a[i] << " "; cout << endl;
}