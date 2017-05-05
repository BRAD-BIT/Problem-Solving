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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 100 + 7;
int const MOD = 1e9 + 7;
vector<vector<pair<int, ii>>>G;
int s, t; int vis[MAX]; ii ans;
void DFS(int node,ll w, int time)
{
	if (node == t){ if (ans.second > time)ans = ii(w, time); else if (ans.second == time)ans = ii(min(w, ans.first), time); return; }
	lop(i, 0, sz(G[node]))
	{
		pair<int, ii>child = G[node][i];
		if (!vis[child.first])
		{
			vis[child.first] = 1;
			DFS(child.first, w + child.second.second, time + child.second.first);
			vis[child.first] = 0;
		}
	}
}
int main()
{
	int T, n, m, q; sc(T);
	while(T--)
	{
		sc(n), sc(m); G.resize(n);
		lop(i, 0, m)
		{
			int a, b, c, d; sc(a), sc(b), sc(c), sc(d); --a, --b;
			G[a].push_back(pair<int, ii>(b, ii(c, d))), G[b].push_back(pair<int, ii>(a, ii(c, d)));
		}
		sc(q);
		lop(i, 0, q)
		{
			ans = ii(oo, oo);
			memset(vis, 0, MAX);
			sc(s), sc(t); s--, t--;
			vis[s] = 1;
			DFS(s, 0, 0);
			if (ans.first == oo)cout << "No Path.\n"; else cout << "Distance and time to reach destination is " << ans.first << " & " << ans.second << ".\n";
		}
		G.clear();
		if (T)cout << endl;
	}
}