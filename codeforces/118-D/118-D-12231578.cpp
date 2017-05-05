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
int n1, n2, k1, k2; int mem[103][103][103][4]; int mod = 100000000;
int dp(int sum1,int sum2,int sum3,int last)
{
    if (!sum1&&!sum2)return 1;
    if (last == 1 && sum3 >= k1&&sum2 == 0)return 0;
    if (last == 2 && sum3 >= k2&&sum1 == 0)return 0;
    if (mem[sum1][sum2][sum3][last] != -1)return mem[sum1][sum2][sum3][last];
    mem[sum1][sum2][sum3][last] = 0;int sum31 = 1, sum32 = 1;
    if (last == 1)sum31 = sum3 + 1; else sum31 = 1;
    if (last == 2)sum32 = sum3 + 1; else sum32 = 1;
    if (sum1 != 0 && sum31 <= k1)mem[sum1][sum2][sum3][last] += dp(sum1 - 1, sum2, sum31, 1) % mod;
    if (sum2 != 0 && sum32 <= k2)mem[sum1][sum2][sum3][last] += dp(sum1, sum2 - 1, sum32, 2) % mod;
    return mem[sum1][sum2][sum3][last]%mod;
}
int main()
{
    cin >> n1 >> n2 >> k1 >> k2;
    memset(mem, -1, sizeof mem);
    int ans = dp(n1, n2, 0, -1);
    cout << ans << endl;
}