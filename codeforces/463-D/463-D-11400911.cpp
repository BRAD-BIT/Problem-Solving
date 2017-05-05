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
int n, k; int a[5][1007]; int b[5][1007]; int mem[1007][1007];
bool can_take(int n,int last)
{
	for (int i = 0; i < k; i++)
	{
		if (b[i][n] < b[i][last])return false;
	}
	return true;
}
int dp(int i,int last)
{
	if (i == n)return 0;
	if (mem[i][last] != -1)return mem[i][last];
	int ans1 = 0, ans2 = 0;
	ans1 = dp(i + 1, last);
	if (can_take(a[0][i], last))ans2 = dp(i + 1, a[0][i]) + 1;
	return mem[i][last] = max(ans1, ans2);
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)for (int j = 0; j < n; j++) { cin >> a[i][j]; b[i][a[i][j]] = j; }
	memset(mem, -1, sizeof mem);
	cout << dp(0, 0) << endl;
}