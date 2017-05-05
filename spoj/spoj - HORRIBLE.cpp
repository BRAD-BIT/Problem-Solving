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
const int MOD = 1e9;
class Fenwick_Tree
{
public:
	vll FT[2];
	Fenwick_Tree(int n)
	{
		FT[0].resize(n + 1, 0);
		FT[1].resize(n + 1, 0);
	}
	int LSOne(int x)
	{
		return x&-x;
	}
	void update(int f, int i, ll v)
	{
		if (i >= sz(FT[f]))return;
		FT[f][i] += v; 
		update(f, i + LSOne(i), v);
	}
	void _update(int a, int b, ll v)
	{
		update(0, a, v);
		update(0, b + 1, -v);
		update(1, a, v * (a - 1));
		update(1, b + 1, -v * b);
	}
	ll RSQ(int f, int b)
	{
		if (b <= 0)return 0;
		return FT[f][b] + RSQ(f, b - LSOne(b));
	}
	ll RSQ(int b)
	{
		return RSQ(0, b) * b - RSQ(1, b);
	}
	ll _RSQ(int a, int b)
	{
		return RSQ(b) - RSQ(a - 1);
	}
};
int main()
{
	int t; sc(t);
	while (t--)
	{
		int n, m; sc(n), sc(m);
		Fenwick_Tree FT(n);
		lop(i, 0, m) 
		{
			int x, a, b, v; sc(x), sc(a), sc(b);
			if (!x)
			{
				sc(v);
				FT._update(a, b, v);
			}
			else
			{
				pr4(FT._RSQ(a, b));
			}
		}
	}
}