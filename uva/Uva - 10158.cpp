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
#define iter(it,S) for(set<int>::iterator it = S.begin(); it != S.end(); ++it)
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
int const MAX = 1000 + 7;
int const MOD = 1e9 + 7;
class unionFind
{
	vi rank, parent, e;
public:
	unionFind(int n)
	{
		rank.resize(n); parent.resize(n), e.resize(n,-1);
		for (int i = 0; i < n; ++i)rank[i] = 0, parent[i] = i;
	}
	int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
	bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
	int union_set(int i, int j) {
		if (i == -1 || j == -1)return max(i, j);
		int ret = find_set(i);
				if (!isSameSet(i, j))
				{
					int x = find_set(i), y = find_set(j); if (rank[x] > rank[y]) parent[y] = x, ret = x;
					else { parent[x] = y; ret = y; if (rank[x] == rank[y]) rank[y]++; }
				}
				return ret;
			}
	void setFriend(int i, int j) 
	{
		i = find_set(i), j = find_set(j);
		int u = union_set(i, j);int v = union_set(e[i], e[j]);
		e[u] = v;if(v!=-1)e[v] = u;
	}
	void setEnemy(int i, int j)
	{
		i = find_set(i), j = find_set(j);
		int u = union_set(e[i], j);int v = union_set(e[j], i);
		if (u != -1)e[u] = v;if (v != -1)e[v] = u;
	}
	bool areFriends(int i, int j){return isSameSet(i, j);}
	bool areEnemies(int i, int j){i = find_set(i), j = find_set(j);return e[i] == j;}
};
int main()
{
	//R_("input.txt");
	int n, x, y, z; cin >> n; unionFind UN(n); int uu = 0;
	while (1)
	{
		cin >> x >> y >> z; if (x == 0){ return 0; }
		if (x == 1){ if (UN.areEnemies(y, z)){ pr1(-1); continue; }UN.setFriend(y, z); continue; }
		if (x == 2){ if (UN.areFriends(y, z)){ pr1(-1); continue; }UN.setEnemy(y, z); continue; }
		if (x == 3){ pr1(UN.areFriends(y, z)); continue; }		
		pr1(UN.areEnemies(y, z));
	}
}