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
struct cake{int a, b, c, d; };
int n, m, c, d; cake a[15]; int mem[15][1007][15];
int dp(int i,int reminder,int last)
{
    if (i == m)return 0;
    if (mem[i][reminder][last] != -1)return mem[i][reminder][last];
    int j = 1; int ans1 = 0, ans2 = 0;
    ans1 = dp(i + 1, reminder, last);
    while (reminder - j*a[i].c >= 0 && a[i].a - j*a[i].b >= 0)
    {
        ans2 = max(ans2, dp(i + 1, reminder - a[i].c*j, i) + j*a[i].d);
        j++;
    }
    return mem[i][reminder][last] = max(ans1, ans2);
}
int main()
{
    cin >> n >> m >> c >> d;
    for (int i = 0; i < m; i++)cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    a[m].a = 0; a[m].b = 0; a[m].c = c; a[m].d = d; m++;
    memset(mem, -1, sizeof mem);
    int ans = dp(0, n, -1);
    cout << ans << endl;
}