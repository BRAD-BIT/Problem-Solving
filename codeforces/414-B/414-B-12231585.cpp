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
int k, n; 
ll MOM[2007][2007];
ll dp(int last, int reminder)
{
    if (reminder == 0){ return 1; }
    if (MOM[last][reminder] != -1)return MOM[last][reminder];
    ll v = 1; MOM[last][reminder] = 0;
    while (last* v <= n)
    {
        MOM[last][reminder] += dp(last*v, reminder - 1);
        MOM[last][reminder] %= (1000000007);
        v++;
    }
    return MOM[last][reminder];
}
int main()
{
    for (int i = 0; i < 2007; i++)
    for (int j = 0; j < 2007; j++)
    {
        MOM[i][j] = -1;
    }
    cin >> n >> k;
    ll ans = dp(1, k);
    cout << ans << endl;
}