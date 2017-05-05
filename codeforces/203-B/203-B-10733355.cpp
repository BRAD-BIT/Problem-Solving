#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int s[1011][1011];
int main()
{
    int n, m, i, x, y, j, k;
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        for (k = 0; k<3; k++)
        for (j = 0; j<3; j++)
        {
            s[x + k][y + j]++;
            if (s[x + k][y + j] == 9)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}