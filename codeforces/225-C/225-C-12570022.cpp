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
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define sz(v)      (ll)v.size()
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1000 + 7;
int const MOD = 1e9 + 7;
int arr[MAX]; int n, m, x, y; char grid[MAX][MAX]; int mem[MAX][MAX][2];
int dp(int i, int c, int t)
{
	if (i == m)if (c >= x)return 0; else return oo; 
	if(c!=-1)if (mem[i][c][t] != -1)return mem[i][c][t];
	int sum0 = arr[i], sum1 = n - arr[i];
	if (c == -1)return mem[i][c][t]=min(dp(i + 1, 1, 1) + sum1, dp(i + 1, 1, 0) + sum0);
	if (c >= y){ if (t == 0)return mem[i][c][t] = dp(i + 1, 1, 1) + sum1; if (t == 1)return mem[i][c][t]= dp(i + 1, 1, 0) + sum0; }
	if (c >= x){ if (t == 0)return mem[i][c][t] = min(dp(i + 1, c + 1, 0) + sum0, dp(i + 1, 1, 1) + sum1); if (t == 1)return mem[i][c][t]=min(dp(i + 1, c + 1, 1) + sum1, dp(i + 1, 1, 0) + sum0); }
	if (c<x){ if (t == 0)return mem[i][c][t]=dp(i + 1, c + 1, t) + sum0; if (t == 1)return mem[i][c][t] = dp(i + 1, c + 1, t) + sum1; }
}
int main()
{
	cin >> n >> m >> x >> y;
	lop(i, 0, n)lop(j, 0, m)cin >> grid[i][j];
	lop(i, 0, m){int sum = 0; lop(j, 0, n)sum += (grid[j][i] == '#'); arr[i] = sum;}
	memset(mem, -1, sizeof mem);
	int ans = dp(0, -1, 0); cout << ans << endl;
}