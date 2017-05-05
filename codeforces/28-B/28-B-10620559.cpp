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
int visited[107] = { 0 };
int counter = 0; bool test;
void DFS(int from,int to)
{
    if (from == to){ test = true; return; }
    visited[from] = counter;
    for (int i = 0; i < graph[from].size();i++)
    {
        int child = graph[from][i];
        if (visited[child] != counter)DFS(child, to);
    }
}
int main()
{
    int now[107], wanted[107], favourite[107]; int n; cin >> n;
    for (int i = 0; i < n; i++){ cin >> wanted[i]; now[i] = i + 1; }
    for (int i = 0; i < n; i++){ cin >> favourite[i]; }
    graph = vector<vector<int>>(n);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        if (abs(i - j) == favourite[i])
        {
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        test = false;
        counter++;
        if (now[i] != wanted[i])
        {
            for (int j = 0; j < n; j++)
            {
                if (now[j] == wanted[i]&&now[j]!=wanted[j])
                {
                    DFS(i, j);
                    if (test)swap(now[i], now[j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (now[i] != wanted[i]){ cout << "NO" << endl; return 0; }
    }
    cout << "YES" << endl;
}