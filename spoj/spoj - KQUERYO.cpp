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
int arr[MAX];
class segment_tree
{
public:
	vvi ST; int from; int to; int k;
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
	int query(int p, int start, int end)
	{
		if (from > end || to < start)return 0;
		if (from <= start &&end <= to)
		{
			return ST[p].size() - (upper_bound(ST[p].begin(), ST[p].end(), k) - ST[p].begin());
		}
		int mid = (start + end) / 2;
		return query(2 * p, start, mid) + query(2 * p + 1, mid + 1, end);
	}
};
int main()
{
	int n; cin >> n;
	segment_tree ST(n);
	lop(i, 0, n)sc(arr[i]);
	int q; cin >> q;
	ST.build(1, 0, n - 1);
	int last_ans = 0;
	lop(i, 0, q)
	{
		cin >> ST.from >> ST.to >> ST.k;
		ST.from = (last_ans^ST.from) - 1, ST.to = (last_ans^ST.to) - 1, ST.k = last_ans^ST.k;
		last_ans = ST.query(1, 0, n - 1);
		cout << last_ans << endl;
	}
}