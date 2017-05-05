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
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
#include<locale>
#include<codecvt>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("in.txt"),W_("out.txt")
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
#define pr3(n)     cout<<fixed<<setprecision(4)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
ld sum = 0;
class unionFind
{
public:
	vll size, parent;
	unionFind(int n)
	{
		size.resize(n); parent.resize(n);
		for (int i = 0; i < n; ++i)size[i] = 1, parent[i] = i;
	}
	int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
	bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
	bool union_set(int i, int j,int ani) {
		if (!isSameSet(i, j))
		{
			int x = find_set(i), y = find_set(j); 
			sum += (size[x] * size[y] * 2 * ani);
			if (size[x] > size[y]) parent[y] = x, size[x] += size[y];
			else { parent[x] = y;  size[y] += size[x]; }
			return 1;
		}
		return 0;
	}
};
vvi G; ii arr[MAX];int used[MAX];
int main()
{
	ll n, m; scl(n), scl(m); G.resize(n);
	lop(i, 0, n)sc(arr[i].first), arr[i].second = i;
	lop(i, 0, m)
	{
		int a, b; sc(a), sc(b); a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	sort(arr, arr + n);
	unionFind UN(n);
	loop(i, n, 0)
	{
		int x = arr[i].second, y = arr[i].first;
		used[x] = 1;
		lop(j, 0, G[x].size())
		{
			if (used[G[x][j]])
			{
				UN.union_set(x, G[x][j], y);
			}
		}	
	}
	sum /= n;
	sum /= (n - 1);
	pr3(sum);
}