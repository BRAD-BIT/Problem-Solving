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
int n, k, d, mod = 1000000007; map<pair<int, int>, ll>mem, mem2;
ll dp(int take,int sum)
{
    if (sum == n){ if (take)return 1; else return 0; }
    if (sum > n)return 0;
    if (mem2[make_pair(take, sum)] == 1)return mem[make_pair(take, sum)];
    mem2[make_pair(take, sum)] = 1;
    for (int i = 1; i <= k; i++)
    {
        int temp = take;
        if (i >= d)temp = 1;
        mem[make_pair(take,sum)]+=(dp(temp, sum + i))%mod;
    }
    return mem[make_pair(take, sum)]%mod;
}
int main()
{
    cin >> n >> k >> d;
    int ans = dp(0, 0);
    cout << ans << endl;
}