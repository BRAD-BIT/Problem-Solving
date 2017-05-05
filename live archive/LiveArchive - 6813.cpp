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
//#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
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
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 50 + 7;
int const MOD = 1e9 + 7;
char grid[MAX][MAX];
int vis[MAX][MAX];
ii out; int N, M;
int main()
{
	int T = 1;
	while (1)
	{
		cin >> M >> N;
		if (N == 0 && M == 0)return 0;
		ii s; char dir;
		lop(i, 0, N)lop(j, 0, M){ cin >> grid[i][j]; if (grid[i][j] == '*')s = ii(i, j); }
		if (s.first == 0)dir = 'D';if (s.first == N - 1)dir = 'U';
		if (s.second == M - 1)dir = 'L';if (s.second == 0)dir = 'R';
		while (1)
		{
			if (dir == 'L')loop(i, s.second , 0)
				if (grid[s.first][i] != '.')
				{
				if (grid[s.first][i] == 'x'){ grid[s.first][i] = '&'; goto N; }s.second = i; if (grid[s.first][i] == '/')dir = 'D'; else dir = 'U'; goto NEXT;
				}

			if (dir == 'R')lop(i, s.second + 1, M)
				if (grid[s.first][i] != '.')
				{
				if (grid[s.first][i] == 'x'){ grid[s.first][i] = '&'; goto N; }s.second = i; if (grid[s.first][i] == '/')dir = 'U'; else dir = 'D'; goto NEXT;
				}

			if (dir == 'D')lop(i, s.first+1, N)
				if (grid[i][s.second] != '.')
				{
				if (grid[i][s.second] == 'x'){ grid[i][s.second] = '&'; goto N; }s.first = i; if (grid[i][s.second] == '/')dir = 'L'; else dir = 'R'; goto NEXT;
				}
			
			if (dir == 'U')loop(i, s.first , 0)
				if (grid[i][s.second] != '.')
				{
				if (grid[i][s.second] == 'x'){ grid[i][s.second] = '&'; goto N; }s.first = i; if (grid[i][s.second] == '/')dir = 'R'; else dir = 'L'; goto NEXT;
				}
		NEXT:;
		}
		N:;
		cout << "HOUSE " << T++ << endl;
		lop(i, 0, N){ lop(j, 0, M)cout << grid[i][j]; cout << endl; }
	}
}