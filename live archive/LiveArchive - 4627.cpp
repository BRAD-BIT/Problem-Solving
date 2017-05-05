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
int grid[MAX][MAX], q[MAX*MAX]; vii arr; int n, m;
bool comp(ii a, ii b)
{
	return grid[a.first][a.second] < grid[b.first][b.second];
}
class unionFind
{
public:
	vi parent, rank; int forest;
	unionFind()
	{
		parent.resize(n*m), rank.resize(n*m);
		lop(i, 0, n)lop(j, 0, m)rank[i*m + j] = 0, parent[i*m + j] = i*m + j; forest = 0;
	}
	int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
	bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
	bool union_set(ii u, ii v) {
		int i = u.first*m + u.second, j = v.first*m + v.second;
		if (!isSameSet(i, j))
		{
			forest--;
			int x = find_set(i), y = find_set(j); if (rank[x] > rank[y]) parent[y] = x;
			else { parent[x] = y; if (rank[x] == rank[y]) rank[y]++; }
			return 1;
		}
		return 0;
	}
};
int main()
{
	//R_W;
	int T; sc(T);
	while (T--)
	{
		int t; sc(n), sc(m); unionFind UN;
		lop(i, 0, n)lop(j, 0, m){ sc(grid[i][j]); arr.push_back(ii(i, j)); }

		sort(all(arr), comp);
		sc(t); vi ans;
		int e = n*m;
		lop(i, 0, t)sc(q[i]);
		loop(i, t, 0)
		{
			int x = 0, y = q[i];
			loop(j, e, 0)if (grid[arr[j].first][arr[j].second] > y)++x; else break;
			UN.forest += x;
			loop(j, e, 0)
			{
				if (grid[arr[j].first][arr[j].second] > y)
				{
					lop(k, 0, 4)
					{
						int r = arr[j].first + dr[k], c = arr[j].second + dc[k];
						if (c < 0 || c >= m || r < 0 || r >= n)continue;
						if (grid[r][c] <= y)continue;
						UN.union_set(ii(arr[j].first, arr[j].second), ii(r, c));
					}
				}
				else break;
				e = j;
			}
			ans.push_back(UN.forest);
		}
		loop(i, sz(ans), 0)pr2(ans[i]); cout << endl;
		arr.clear();
	}
}