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
vii G[MAX][MAX];
int vis[MAX][MAX];
ii out; int N, M;
vector<ii>can_reach(int x,int y,char c)
{
	vector<ii>ans;
	if (c == '0')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x + 1, y)), ans.push_back(ii(x, y - 1)), ans.push_back(ii(x, y + 1));
	if (c == '1')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x + 1, y)), ans.push_back(ii(x, y + 1));
	if (c == '2')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x, y - 1)), ans.push_back(ii(x, y + 1));
	if (c == '3')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x, y + 1));
	if (c == '4')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x + 1, y)), ans.push_back(ii(x,y-1));
	if (c == '5')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x + 1, y));
	if (c == '6')ans.push_back(ii(x - 1, y)), ans.push_back(ii(x, y - 1));
	if (c == '7')ans.push_back(ii(x - 1, y));
	if (c == '8')ans.push_back(ii(x + 1, y)), ans.push_back(ii(x, y - 1)), ans.push_back(ii(x, y + 1));
	if (c == '9')ans.push_back(ii(x + 1, y)), ans.push_back(ii(x, y + 1));
	if (c == 'A')ans.push_back(ii(x, y - 1)), ans.push_back(ii(x, y + 1));
	if (c == 'B')ans.push_back(ii(x, y + 1));
	if (c == 'C')ans.push_back(ii(x + 1, y)), ans.push_back(ii(x, y - 1));
	if (c == 'D')ans.push_back(ii(x + 1, y));
	if (c == 'E')ans.push_back(ii(x, y - 1));
	return ans;
}
bool  NO_SOLUTION, UNREACHABLE_CELL, MULTIPLE_PATHS, MAZE_OK;
void DFS(int r, int c, int pr, int pc)
{
	vis[r][c] = DFS_GRAY;
	lop(i, 0, sz(G[r][c]))
	{
		ii child = G[r][c][i];
		if (child.first >= N || child.second >= M || child.first == -1 || child.second == -1)continue;
		if (vis[child.first][child.second] == DFS_WHITE)DFS(child.first, child.second, r, c);
		if (vis[child.first][child.second]==DFS_GRAY&&!(child.first==pr&&child.second==pc))
		{
			MULTIPLE_PATHS = 1; MAZE_OK = 0;
		}
	}
	vis[r][c] = DFS_BLACK;
}
int main()
{
	while (1)
	{
		cin >> N >> M; if (N == 0 && M == 0)break;
		NO_SOLUTION=0, UNREACHABLE_CELL=0, MULTIPLE_PATHS=0, MAZE_OK=1;
		vii open;
		lop(i, 0, N)lop(j, 0, M)
		{
			char c; cin >> c; G[i][j].clear(); G[i][j] = can_reach(i, j, c);
			if (j == 0)lop(k, 0, sz(G[i][j]))if (G[i][j][k].second == -1){ open.push_back(ii(i, j)); }
			if (j == M-1)lop(k, 0, sz(G[i][j]))if (G[i][j][k].second == M){ open.push_back(ii(i, j)); }

			if (i == 0)lop(k, 0, sz(G[i][j]))if (G[i][j][k].first == -1){ open.push_back(ii(i, j)); }
			if (i == N-1)lop(k, 0, sz(G[i][j]))if (G[i][j][k].first == N){ open.push_back(ii(i, j)); }
		}
		memset(vis, 0, sizeof vis);
		DFS(open[0].first, open[0].second, -1, -1);
		lop(i, 0, N)lop(j, 0, M)if (!vis[i][j])
		{
			if (ii(i, j) == open[1]){ NO_SOLUTION = 1; MAZE_OK = 0; }
			else { UNREACHABLE_CELL = 1; MAZE_OK = 0; }
		}
		if (NO_SOLUTION)cout << "NO SOLUTION\n"; else
			if (UNREACHABLE_CELL)cout << "UNREACHABLE CELL\n";else
			if (MULTIPLE_PATHS)cout << "MULTIPLE PATHS\n";else
					if (MAZE_OK)cout << "MAZE OK\n";
		open.clear();
	}
}