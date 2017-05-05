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
#define  oo  1e9
using namespace std;
const int MAX = 300; int n;
ll graph[MAX][MAX];
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)for (int j = 0; j < n; ++j)cin >> graph[i][j];
    int k; cin >> k;
    for (int v = 0; v < k; v++)
    {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        for (int k = 0; k < 2; k++)
        {
            swap(a, b);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][a] + c + graph[b][j]);
                }
            }
        }
        ll sum = 0;
        for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)if(j>=i)sum += graph[i][j];
        cout << sum << " ";
    }
    cout << endl;
}