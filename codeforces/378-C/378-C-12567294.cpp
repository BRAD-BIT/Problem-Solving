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
#include<functional>
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
int dr[] = { 0, 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };
char maze[504][504]; int n, m, k;
int visited[504][504];
void dfs(int r, int c)
{
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++)
    { 
        if (r + dr[i] < n&&c + dc[i] < m&&r+dr[i]>=0&&c+dc[i]>=0)if (!visited[r + dr[i]][c + dc[i]]&&maze[r+dr[i]][c+dc[i]]!='#')dfs(r + dr[i], c + dc[i]);
    }
    if (k != 0&&maze[r][c]!='#'){ maze[r][c] = 'X'; k--; }
}
int main()
{
    cin >> n >> m >> k; pair<int, int>start;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++){ cin >> maze[i][j]; if (maze[i][j] != '#')start = make_pair(i, j); }
    memset(visited, 0, sizeof visited);
    dfs(start.first, start.second);
    for (int i = 0; i < n; i++){for (int j = 0; j < m; j++)cout << maze[i][j]; cout << endl;}
}