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
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
int N, C;
vvi city; vvii G; int deg[MAX], cnt, bridge[MAX];
int dfs_num[MAX], dfs_low[MAX];vi odd;
void tarjan(int v, int p)
{
	dfs_num[v] = dfs_low[v] = ++cnt;
	loop(i, sz(G[v]),0)
	{
		ii child = G[v][i];
		if (dfs_num[child.first] == -1)
		{
			tarjan(child.first, v);
			if (dfs_low[child.first] > dfs_num[v])
			{
				bridge[child.second] = 1; 
			}
			dfs_low[v] = min(dfs_low[v], dfs_low[child.first]);
		} 
		else if (child.first != p) dfs_low[v] = min(dfs_low[v], dfs_num[child.first]);
	}
}
int main()
{
	while (1)
	{
		sc(N), sc(C); if (N == 0 && C == 0)break;
		city.resize(N), G.resize(C); cnt = 0;
		memset(dfs_num, -1, sizeof dfs_num);
		memset(deg, 0, sizeof deg);
		memset(bridge, 0, sizeof bridge);
		lop(i, 0, C)
		{
			int k; sc(k); lop(j, 0, k){ int x; sc(x); city[x].push_back(i); }
		}
		lop(i, 0, N)
		{
			int u = city[i][0], v=u;
			if (city[i].size() == 2)v = city[i][1];
			G[u].push_back(ii(v, i)), G[v].push_back(ii(u, i));
			++deg[u], ++deg[v];
		}
		lop(i, 0, C)if (deg[i] % 2 != 0)odd.push_back(i);
		int ncomp = 0;
		for (int i = 0; i < C && ncomp <= 1; ++i)
			if (deg[i] != 0 && dfs_num[i]==-1)
			tarjan(i, -1),++ncomp;
		if (odd.size()>2 || ncomp>1)cout << "-1\n";
		else
		if (odd.size()==0)cout << "0\n";
		else {
			ll ans = oo;
			lop(i, 0, 2)
			{
				ll cur = odd[i];
				if (G[cur].size() == 1){ ans = min(ans, G[cur][0].second); continue; }
				loop(j, sz(G[cur]), 0)
					if (!bridge[G[cur][j].second])ans = min(ans, G[cur][j].second);
			}
			cout << ans << endl;
		}
	NEXT:;
		G.clear(), city.clear(), odd.clear();
	}
}