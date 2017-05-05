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
int const MAX = 2000 + 7;
int const MOD = 1e9 + 7;
char g[MAX][MAX];
int dis[MAX][MAX];
vii s; int X, Y, T, L, W;
void bfs()
{
	memset(dis, -1, sizeof dis);
	queue<ii>q; lop(i, 0, sz(s))q.push(s[i]), dis[s[i].first][s[i].second] = 1;
	while (!q.empty())
	{
		ii cur = q.front(); q.pop(); int dep = dis[cur.first][cur.second];
		lop(i, 0, 4)
		{
			int x = cur.second + dr[i], y = cur.first + dc[i];
			if (x > X || y > Y || x == 0 || y == 0)continue;
			if (g[y][x] != '.')continue;
			if (dis[y][x] == -1){
				dis[y][x] = dep + 1;
				q.push(ii(y, x));
			}
		}
	}
	int ans = 0;
	lop(i, 1, Y+1)lop(j, 1, X+1)if (dis[i][j] <=T&&dis[i][j]!=-1)ans++;
	cout << ans << endl;
}
int main()
{
	while (1)
	{
		int  L, W;
		cin >> X;
		if (X == -1) break;
		scanf("%d%d%d%d", &Y, &T, &L, &W);
		lop(i, 0, Y+1)lop(j, 0, X+1)g[i][j] = '.';
		for (int j = 0; j < L; j++) {
			int r, c; scanf("%d%d", &r, &c);
			g[c][r] = 'L';
			s.push_back(ii(c, r));
		}

		for (int j = 0; j < W; j++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int dx = x2 - x1;
			int dy = y2 - y1;
			if (dx != 0) dx = dx / abs(dx);
			if (dy != 0) dy = dy / abs(dy);
			g[y1][x1] = 'W';
			while (x1 != x2 || y1 != y2) { x1 += dx; y1 += dy; g[y1][x1] = 'W'; }
		}

		bfs();
		s.clear();
	}
}