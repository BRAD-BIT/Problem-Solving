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
#include <cstdio>
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
int n, a; int G1[111][111];long double G2[111][111];
void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (G1[i][k] + G1[k][j] <= G1[i][j])
                {if (G1[i][k] + G1[k][j] < G1[i][j])G2[i][j] = 0; G1[i][j] = G1[i][k] + G1[k][j]; G2[i][j] += (G2[i][k] * G2[k][j]);}
}
int main()
{
    int m; cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)G1[i][j] = oo, G2[i][j] = 0;
    for (int i = 0; i < m; ++i){ int a, b; cin >> a >> b; --a, --b; G1[a][b] = G1[b][a] = G2[a][b] = G2[b][a] = 1; }
    floyd();
    long double ans = 1.0;
    for (int i = 1; i < n-1; i++)if (G1[0][i] + G1[i][n-1] == G1[0][n-1])ans=max(ans,(2*G2[0][i]*G2[i][n-1])/G2[0][n-1]);
    cout << fixed << setprecision(10) << ans << endl;
}