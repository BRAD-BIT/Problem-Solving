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
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
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
int visited[1000] = { 0 };
int found = false;
void DFS(int from,int to)
{
    if (from == to){ found = true; return; }
    visited[from] = 1;
    for (int i = 0; i < graph[from].size(); i++)
    {
        int child = graph[from][i];
        if (!visited[child])DFS(child, to);
    }
}
int main()
{
    int n; cin >> n; pair<int, int> a[2000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (a[j].first == a[i].first || a[j].second == a[i].second){ graph[i].push_back(j); graph[j].push_back(i); }
            }
        }
    }
    int sum = 0; int h = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                found = false;
                DFS(i, j);
                memset(visited, 0, 1000);
                if (!found)
                {
                    int x, y;
                    if (a[i].first>a[j].first&&a[i].second > a[j].second)
                    {
                        x = a[j].first;
                        y = a[i].second;
                    }
                    else
                    if (a[j].first>a[i].first&&a[j].second > a[i].second)
                    {
                        x = a[i].first;
                        y = a[j].second;
                    }
                    else
                    {
                        x = max(a[i].first, a[j].first);
                        y = max(a[i].second, a[j].second);
                    }
                    a[h].first = x;
                    a[h].second = y;
                    vector<int>vvv;
                    for (int g = 0; g < h; g++)
                    {
                        if (a[g].first == x || a[g].second == y){ graph[g].push_back(h); vvv.push_back(g); }
                    }
                    graph.push_back(vvv);
                    h++;
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
}