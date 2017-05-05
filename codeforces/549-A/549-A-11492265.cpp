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
int n, m;  char a[60][60]; string s = "acef";  int ans = 0;
void check(int i,int j)
{
    string temp;
    temp += a[i][j];
    if (i + 1 < n)temp += a[i + 1][j];
    if (j + 1 < m)temp += a[i][j + 1];
    if (i + 1 < n&&j + 1 < m)temp += a[i + 1][j + 1];
    sort(temp.begin(), temp.end());
    if (temp == s)ans++;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    for (int i = 0; i < n; i++)for (int j = 0; j< m; j++)check(i, j);
    cout << ans << endl;
}