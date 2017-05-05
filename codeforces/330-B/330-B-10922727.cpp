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
    int n, m; cin >> n >> m; int a[1007] = { 0 };
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x; a[x-1]++;
        cin >> x; a[x-1]++;
    }
    int x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0){ x = i + 1; break; }
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n; i++)
    {
        if (x != i + 1)cout << x << " " << i + 1 << endl;
    }
}