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
struct rec{ int x1, y1, x2, y2; }; int n; rec a[104];
int solve(int r, int c)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (r >= a[i].x1&&r <= a[i].x2 && c >= a[i].y1&&c <= a[i].y2)sum++;
    }
    return sum;
}
int main()
{
    cin >> n; int ans = 0;
    for (int i = 0; i < n; i++)cin >> a[i].y1 >> a[i].x1 >> a[i].y2 >> a[i].x2;
    for (int i = 0; i < 100; i++)for (int j = 0; j < 100; j++)ans += solve(i+1, j+1);
    cout << ans << endl;
}