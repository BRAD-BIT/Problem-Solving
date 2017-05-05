//In the name of Allah
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
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("in.txt"),W_("out.txt")
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
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1000 + 7;
const int MOD = 1e9 + 7;
int lec[MAX], sum[MAX],mem[MAX][MAX], ans, n, L, c;
int dp(int i, int j)
{
	if (j == n)return 0;
	if (i == ans)return oo;
	if (mem[i][j] != -1)return mem[i][j];
	int ans = oo;
	lop(k, j, n)
	{
		int TT = sum[j] - sum[k] + lec[k];
		if (TT > L)break;
		int D;
		if (TT == L)D = 0;
		else
		if (L - TT <= 10)D = -c;
		else D = ((L - TT) - 10)*((L - TT) - 10);
		ans = min(ans, dp(i + 1, k + 1) + D);
	}
	return mem[i][j]=ans;
}
int main()
{
	int x = 1;
	while (cin >> n&&n)
	{
		cin >> L >> c;
		lop(i, 0, n)cin >> lec[i];
		sum[n - 1] = lec[n - 1];
		loop(i, n - 1, 0)sum[i] = sum[i + 1] + lec[i];
		int T = 0; ans = 0;
		lop(i, 0, n)
		{
			if (T - lec[i] >= 0)T -= lec[i];
			else { T = L - lec[i]; ans++; }
		}
		memset(mem, -1, sizeof mem);
		if (x > 1)cout << endl;
		printf("Case %d:\n", x++);
		printf("Minimum number of lectures: %d\n", ans);
		printf("Total dissatisfaction index: %d\n", dp(0, 0));
	}
}