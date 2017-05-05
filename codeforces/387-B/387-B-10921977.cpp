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
struct can{ int value, can_change; };
int main()
{
    int n, m; cin >> n >> m; int a[3007];can b[3007];
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < m; i++){ cin >> b[i].value; b[i].can_change = 1; }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        bool test = false;
        for (int j = 0; j < m; j++)
        {
            if (b[j].value == a[i]){ test = true; break; }
        }
        if (!test)
        {
            for (int j = 0; j < m; j++)
            {
                if (b[j].can_change)
                {
                    if (b[j].value>a[i])
                    {
                        b[j].value = a[i];
                        b[j].can_change = 0;
                        test = true; break;
                    }
                }
            }
        }
        if (!test)sum++;
    }
    cout << sum << endl;
}