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
int a[100007] = { 0 };
int main()
{
    int n, m; cin >> n>> m;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        a[x - 1]++; a[y - 1]++;
    }
    sort(a, a + n);
    if (a[0] == 1 && a[1] == 1)
    {
        bool test = true;
        for (int i = 2; i < n; i++)
        {
            if (a[i] != 2){ test = false; break; }
        }
        if (test){ cout << "bus topology" << endl; return 0; }
    }
    bool test = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 2){ test = false; break; }
    }
    if (test){ cout << "ring topology" << endl; return 0; }
    test = true;
    if (a[n - 1] == n - 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] != 1){ test = false; break; }
        }
        if (test){ cout << "star topology" << endl; return 0; }
    }
    cout << "unknown topology" << endl;
}