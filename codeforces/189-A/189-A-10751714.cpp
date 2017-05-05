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
int a, b, c, n; int Momization[1000000];
int Cut_Ribbon(int sum1)
{
    if (sum1 == 0){ return 0; }
    if (sum1 < 0)return -1000000;
    if (Momization[sum1] != -1)return Momization[sum1];
    return  Momization[sum1] = max(Cut_Ribbon(sum1 - a)+1, max(Cut_Ribbon(sum1 - b)+1, Cut_Ribbon(sum1 - c)+1));
}
int main()
{
    memset(Momization, -1, 1000000); cin >> n >> a >> b >> c;
    int ans = Cut_Ribbon(n);
    cout << ans << endl;
}