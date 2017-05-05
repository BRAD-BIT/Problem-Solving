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
#include<cstdio>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define pr2(n)     printf("%d " ,n)
#define pr1(n)     printf("%d\n",n)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int a[110]; ll mem[110][100000]; int n;
ll dp(int i,ll sum)
{
    if (i == n)
    {
        if (sum % 2 != 0)return 0; else return -oo;
    }
    if (mem[i][sum] != -999999999999999)return mem[i][sum];
    ll ans1=dp(i + 1, sum + a[i])+a[i];
    ll ans2=dp(i + 1, sum);
    return mem[i][sum] = max(ans1, ans2);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < 110; i++)for (int j = 0; j < 100000; j++)mem[i][j] = -999999999999999;
    ll ans = dp(0, 0);
    if (ans < 0)cout << 0 << endl;else cout << ans << endl;
}