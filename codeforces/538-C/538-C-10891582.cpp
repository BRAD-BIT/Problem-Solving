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
struct Mou{ int day, height; };
int main()
{
    ll n, m; cin >> n >> m; Mou a[100007]; ll MAX = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].day >> a[i].height; if (a[i].height>MAX)MAX = a[i].height;
    }
    for (int i = 1; i < m; i++)
    {
        if (abs(a[i - 1].day - a[i].day) < abs(a[i - 1].height - a[i].height)){ cout << "IMPOSSIBLE"; return 0; }
    }
    for (int i = 1; i < m; i++)
    {
            int ans = a[i - 1].height;
            int rem = abs(a[i - 1].day - a[i].day);
            while (1)
            {
                if (ans + 1 - (rem-1) > a[i].height)break;
                else
                {
                    ans++;
                    rem--;
                }
            }
            if (ans > MAX)MAX = ans;
    }
    int b = n - a[m - 1].day + a[m-1].height;
    if (b > MAX)MAX = b;
    if (a[0].day != 1)
    {
        b = abs(a[0].day - 1) + a[0].height;
        if (b > MAX)MAX = b;
    }
    cout << MAX << endl;
}