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
bool between(int a, int x, int y)
{
    if (a >= x&&a <= y)return 1; else return 0;
}
int main()
{
    int p, q, l, r; cin >> p >> q >> l >> r; pair<int, int> a[52]; pair<int, int> b[52];
    for (int i = 0; i < p; i++)cin >> a[i].first >> a[i].second;
    for (int i = 0; i < q; i++)cin >> b[i].first >> b[i].second;
    bool test; int sum=0;
    for (int i = l; i <= r; i++)
    {
        test = false;
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < q; k++)
            {
                if (between(a[j].first, b[k].first + i, b[k].second + i) || between(a[j].second, b[k].first + i, b[k].second + i) || between(b[k].first + i, a[j].first, a[j].second) || between(b[k].second + i, a[j].first, a[j].second))test=true;
                if (test)break;
            }
            if (test)break;
        }
        if (test)sum++;
    }
    cout << sum << endl;
}