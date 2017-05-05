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
#include<string>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define  oo  1e12
using namespace std;
const int MAX = 504; int removed[MAX];
ll graph[MAX][MAX];ll ANS[MAX]; int n;
void floyd()
{
    for (int v = n-1; v >= 0; --v)
    {
        int k = removed[v];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        for (int i = v; i < n; ++i)
            for (int j = v; j < n; ++j)
                ANS[v] += graph[removed[i]][removed[j]];
    }
}
int main()
{
    cin >> n; 
    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)cin >> graph[i][j];
    for (int i = 0; i < n; ++i)cin >> removed[i], removed[i]--;
    floyd();
    for (int i = 0; i < n; ++i)cout << ANS[i] << " "; cout << endl;
}