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
int main()
{
    int k, n, m; cin >> k;
    if (k % 2 == 0){cout << "NO\n";return 0;}cout << "YES" << endl;
    n = 4 * (k - 1) + 2;m = 3 * k + 2 * (k - 1)*(k - 1) - 2;
    cout << n << " " << m << endl;

    int x = k - 1, y = 1;
    for (int z = 0; z < 2; z++)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = x; j < x + x; j++)cout << y + i << " " << y + j << endl;
        }
        for (int j = x; j < x + x; j += 2)cout << y + j << " " << y + j + 1 << endl;
        for (int i = 0; i < x; i++)cout << y + i << " " << y + x + x << endl;
        y += x + x + 1;
    }
    cout << 2 * x + 1 << " " << 4 * x + 2 << endl;
}