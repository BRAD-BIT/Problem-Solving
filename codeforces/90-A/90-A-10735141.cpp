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
#define R_W        R_("input.txt"),W_("output.txt")0
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int main()
{
    int r, g, b; cin >> r >> g >> b;
    int ans = 0;
    while (1)
    {
        r -= 2; ans++; if (r <= 0 && b <= 0 && g <= 0)break;
        g -= 2; ans++; if (r <= 0 && b <= 0 && g <= 0)break;
        b -= 2; ans++; if (r <= 0 && b <= 0 && g <= 0)break;
    }
    ans += 29;
    cout << ans << endl;
}