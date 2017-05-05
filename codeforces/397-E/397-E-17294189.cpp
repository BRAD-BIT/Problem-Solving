#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
#define lop(i,a,n) for(ll i=a;i<n;++i)
#define loop(i,n,a)for(ll i=n-1;i>=a;--i)
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
#define pr4(n)     printf("%lld\n",n)
#define pr3(n)     cout<<fixed<<setprecision(2)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS pow(10,-9)
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
vvi Graph;
int tim = 0;
struct node
{
	ll x, k, hk;
};
class segment_tree
{
public:
	vector<node> ST; vll height, s, f;
	ll v, x, k; 
	segment_tree(int n, int root)
	{
		ST.resize(4 * n), height.resize(4 * n), s.resize(n), f.resize(n);
		DFS(root, 0);
	}
	void DFS(int node,int h)
	{
		s[node] = tim++; height[node] = h;
		lop(i, 0, sz(Graph[node]))
		{
			int child = Graph[node][i];
			DFS(child, h + 1);
		}
		f[node] = tim;
	}

	void update(int p, int start, int end)
	{
		if (s[v] >= end || f[v] <= start)return;
		if (s[v]<= start&&f[v] >= end)
		{
			ST[p].k = (ST[p].k + 1LL*MOD - k) % MOD;
			ST[p].x = (ST[p].x + x) % MOD;
			ST[p].hk = (ST[p].hk*1LL + k*height[v]*1LL) % MOD;
			return;
		}
		int mid = (start + end) / 2;
		update(2 * p, start, mid);
		update(2 * p + 1, mid, end);
	}
	ll query(int p, int start, int end)
	{
		ll ans = 0LL;
		ans = (ans + ST[p].x) % MOD;
		ans = (ans + ST[p].hk) % MOD;
		ans = (ans + ST[p].k*height[v])%MOD;
		if (end - start < 2)return ans;
		int mid = (start + end) / 2;
		if (s[v] < mid)
		return (ans + query(2 * p, start, mid)) % MOD;
		return (ans+query(2 * p + 1, mid, end)) % MOD;
	}
};
int main()
{
	int n; sc(n);
	Graph.resize(n);
	lop(i, 0, n - 1)
	{
		int x; sc(x);
		Graph[--x].push_back(i + 1);
	}
	segment_tree ST(n, 0);
	int q; sc(q);
	lop(i, 0, q)
	{
		int t; sc(t);
		if (t == 1)
		{
			scl(ST.v), scl(ST.x), scl(ST.k);
			ST.v--;
			ST.update(1, 0, tim);
		}
		else
		{
			sc(ST.v);
			ST.v--;
			int ans = ST.query(1, 0, tim);
			pr1(ans);
		}
	}
}