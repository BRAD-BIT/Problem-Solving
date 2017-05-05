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
    int n; cin >> n; ll a[100007];
    for (int i = 0; i < n; i++)cin >> a[i]; a[n] = -200;
    ll MAX = min(2, n); ll sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1] + a[i - 2])sum++;
        else
        {
            if (sum != 0)sum += 2;
            if (sum>MAX)MAX = sum;
            sum = 0;
        }
    }
    cout << MAX << endl;
}