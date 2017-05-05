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
#include<string>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define  oo  1e9
using namespace std;
void minmax()
{
}
int main()
{
    int fuck;
    int n; int max[3], min[3]; cin >> n >> min[0] >> max[0] >> min[1] >> max[1] >> min[2] >> max[2];
    int ans[3] = { 0 };
    for (int i = 0; i < 3; i++)ans[i] = min[i], n -= min[i];
    for (int i = 0; i < 3; i++)
    {
        if (ans[i] + n > max[i])ans[i] = max[i], n += min[i] - max[i];
        else { ans[i] = min[i] + n; n = 0; }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}