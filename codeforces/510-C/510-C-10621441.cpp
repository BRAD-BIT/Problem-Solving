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
vector<vector<int>>graph(26);
vector<char>ch;
int visited[26] = { 0 };
int counter = 0; bool cycle = false;
void DFS(int node)
{
    visited[node] = DFS_GRAY;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i];
        if (visited[child] == DFS_GRAY){ cycle = true; return; }
        if (visited[child] == DFS_WHITE)DFS(child);
    }
    ch.push_back(char(node + 'a'));
    visited[node] = DFS_BLACK;
}
int sort()
{
    for (int i = 0; i < 26; i++)
    {
        if (visited[i] == DFS_WHITE)DFS(i);
        if (cycle){ cout << "Impossible" << endl; return 0; }
    }
    return 1;
}
int main()
{
    int n; cin >> n; string name[107];
    for (int i = 0; i < n; i++)cin >> name[i];
    for (int i = 0; i < n - 1; i++)
    {
        bool test = false;
        for (int j = 0; j < min(name[i].length(), name[i + 1].length()); j++)
        {
            if (name[i][j] != name[i + 1][j]){ graph[name[i + 1][j] - 'a'].push_back(name[i][j] - 'a'); test = true; break; }
        }
        if (!test)
        {
            if (name[i].length()>name[i + 1].length()){ cout << "Impossible" << endl; return 0; }
        }
    }
    if (sort()){ for (int i = 0; i < ch.size(); i++)cout << ch[i]; cout << endl; }
}