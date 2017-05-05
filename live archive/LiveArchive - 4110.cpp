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
int const MAX = 1e5 + 7;
int const MOD = 1e9 + 7;
class unionFind
{
	vector<int> rank, parent;
public:
	unionFind(int n)
	{
		rank.resize(n); parent.resize(n);
		for (int i = 0; i < n; ++i)rank[i] = 0, parent[i] = i;
	}
	int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
	bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
	bool union_set(int i, int j) {
		if (!isSameSet(i, j))
		{
			int x = find_set(i), y = find_set(j); if (rank[x] > rank[y]) parent[y] = x;
			else { parent[x] = y; if (rank[x] == rank[y]) rank[y]++; }
			return 1;
		}
		return 0;
	}
};
pair<ii, int>e[MAX]; 
bool comp(pair<ii, int>a, pair<ii, int>b)
{
	return a.second > b.second;
}
int main()
{
	int t, n, m; sc(t); 
	while (t--)
	{
		sc(n), sc(m); unionFind UN(n+1); int ans = 0;
		lop(i, 0, m)cin >> e[i].first.first >> e[i].first.second >> e[i].second;
		sort(e, e + m, comp);
		lop(i, 0, m)if (!UN.union_set(e[i].first.first, e[i].first.second))ans += e[i].second;
		cout << ans << endl;
	}
}