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
int main()
{
    int n; cin >> n;double a[105];
    for (int i = 1; i <= n; i++)cin >> a[i]; a[0] = 0;
    sort(a, a + n+1);
    double ans = 0;
    for (int i = n; i > 0; i-=2)
    {
        ans += PI*pow(a[i], 2) - PI*pow(a[i - 1], 2);
    }
    cout << fixed << setprecision(10) << ans << endl;
}