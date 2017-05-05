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
int n; pair<int, int> a[100007];int mem[100007][2];
int dp(int i,int f,int last)
{
    if (i == n - 1){ return 0; }
    if (mem[i][last] != -1)return mem[i][last];
    int ans1 = 0, ans2 = 0, ans3 = 0;

    if (a[i].first - a[i].second > f)ans1 = dp(i + 1, a[i].first, 0) +1;

    if (a[i].first + a[i].second < a[i+1].first)ans2 = dp(i + 1, a[i].first + a[i].second,1) + 1;

    ans3 = dp(i + 1, a[i].first, 0);

    return mem[i][last]= max(ans1, max(ans2, ans3));
}
int main()
{
    memset(mem, -1, sizeof mem);
    cin >> n; int x; if (n == 1)x = 1; else x = 2;
    for (int i = 0; i < n; i++)cin >> a[i].first >> a[i].second;
    if (n>2){ int ans = dp(1, a[0].first, 0) + x; cout << ans << endl; }
    else
        cout << x << endl;
}