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
int arr[MAX];
class segment_tree
{
public:
	vvi ST; int from; int to; int k; int inrange;
	segment_tree(int n)
	{
		ST.resize(4 * n);
	}
	void build(int p, int start, int end)
	{
		if (start == end)
		{
			ST[p].push_back(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(2 * p, start, mid);
		build(2 * p + 1, mid + 1, end);
		merge(ST[2 * p].begin(), ST[2 * p].end(), ST[2 * p + 1].begin(), ST[2 * p + 1].end(), back_inserter(ST[p]));
	}
	int search(int p)
	{
		int s = 0, e = sz(ST[p]) - 1, mid, ans = -1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (ST[p][mid] >= k) { e = mid - 1; }
			if (ST[p][mid] < k) { ans = mid; s = mid + 1; }
		}
		return ans + 1;
	}
	int query(int p, int start, int end)//get number of numbers in [from,to] that are greater than k
	{
		if (from > end || to < start)return 0;
		if (from <= start &&end <= to)
		{
			int x = search(p);
			if (ST[p].size() > x&&ST[p][x] == k)inrange = 1;
			return x;
		}
		int mid = (start + end) / 2;
		return query(2 * p, start, mid) + query(2 * p + 1, mid + 1, end);
	}
};
int main()
{
	int n, m; sc(n), sc(m);
	lop(i, 0, n)sc(arr[i]);
	segment_tree ST(n);
	ST.build(1, 0, n - 1);
	sort(arr, arr + n);
	lop(i, 0, m)
	{
		int k;
		sc(ST.from), sc(ST.to); sc(k);
		ST.from--, ST.to--; 
		int s = 0, e = n-1, mid;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			ST.k = arr[mid];
			ST.inrange = 0;
			int ret = ST.query(1, 0, n - 1);
			if (ret == k - 1)
			{
				if (ST.inrange) { pr1(arr[mid]); break; }
				s = mid + 1;
			}
			else if (ret >= k)e = mid - 1;
			else s = mid + 1;
		}
		
	}
}