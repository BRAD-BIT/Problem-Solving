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
int G[MAX][MAX], pre[MAX][MAX], on[MAX];
int main()
{
	int u, v; int t = 1; 
	while(1)
	{
		lop(i, 0, MAX)lop(j, 0, MAX)G[i][j] = oo, G[i][i] = 0, on[i] = 0;
		cin >> u >> v; 
		if (u == 0 && v == 0)break;
		while (1)
		{
			G[u][v] = 1; on[u] = 1; on[v] = 1;
			cin >> u >> v; 
			if (u == 0 && v == 0)break;
		 }
		lop(k, 0, MAX)lop(i, 0, MAX)lop(j, 0, MAX)G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
		ll ans = 0, n=0;
		lop(i, 0, MAX)lop(j, 0, MAX)if (i != j&&on[i] && on[j])ans += G[i][j], n++;
		ld out = double(ans) / double(n);
		cout << "Case " << t++ << ": average length between pages = "; pr3(out);cout<< " clicks\n";
		
	}
}