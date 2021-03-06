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
struct node
{
	int prefixSum, suffixSum, Sum, MaxSum;
	node(int x, int y, int z, int w) :prefixSum(x), suffixSum(y), Sum(z), MaxSum(w) {};
};

class SegmentTree
{
public:
	vector<node> ST; int n; int from, to;
	SegmentTree(int num)
	{
		ST.resize(4 * num, node(0, 0, 0, 0));
	}
	node merge(node l, node r)
	{
		node ret(0, 0, 0, 0);
		if (l.prefixSum == -oo)return r;
		if (r.prefixSum == -oo)return l;
		ret.prefixSum = max(l.prefixSum, l.Sum + r.prefixSum);
		ret.suffixSum = max(r.suffixSum, l.suffixSum + r.Sum);
		ret.Sum = l.Sum + r.Sum;
		ret.MaxSum = max(max(l.MaxSum, r.MaxSum), max(ret.Sum, l.suffixSum + r.prefixSum));
		return ret;
	}
	void bulid(int p, int s, int e)
	{
		if (s == e) { ST[p] = node(arr[s], arr[s], arr[s], arr[s]); return; }
		int mid = (s + e) / 2;
		bulid(2 * p, s, mid);
		bulid(2 * p + 1, mid + 1, e);
		ST[p] = merge(ST[2 * p], ST[2 * p + 1]);
	}
	node query(int p, int s, int e)
	{
		if (from > e || to < s)return node(-oo, -oo, -oo, -oo);
		if (from <= s&&to >= e)
		{
			return ST[p];
		}
		int mid = (s + e) / 2;
		return merge(query(2 * p, s, mid), query(2 * p + 1, mid + 1, e));
	}
};
int main()
{
	int t; sc(t);
	while (t--)
	{
		int n, m;
		cin >> n;
		lop(i, 0, n)sc(arr[i]);
		SegmentTree ST(n);
		ST.bulid(1, 0, n - 1);
		cin >> m;
		lop(i, 0, m)
		{
			int x1, y1, x2, y2;
			sc(x1), sc(y1);
			sc(x2), sc(y2);
			x1--, y1--; x2--, y2--;
			if (x2 > y1)
			{
				ST.from = x1, ST.to = y1; int ans2=0;
				int ans1 = ST.query(1, 0, n - 1).suffixSum;
				ST.from = y1 + 1, ST.to = x2 - 1;
				if (ST.from <= ST.to)
				ans2 = ST.query(1, 0, n - 1).Sum;
				ST.from = x2, ST.to = y2;
				int ans3 = ST.query(1, 0, n - 1).prefixSum;
				cout << ans1 + ans2 + ans3 << endl;
			}
			else
			{
				ST.from = x2, ST.to = y1;
				int ans1 = ST.query(1, 0, n - 1).MaxSum;


				ST.from = x1, ST.to = x2-1; 
				int ans2 = ST.query(1, 0, n - 1).suffixSum;
				ST.from = x2, ST.to = y2;
				ans2 += ST.query(1, 0, n - 1).prefixSum;

				ST.from = x1, ST.to = y1;
				int ans3 = ST.query(1, 0, n - 1).suffixSum;
				ST.from = y1+1, ST.to = y2;
				ans3 += ST.query(1, 0, n - 1).prefixSum;

				cout << max(ans1, max(ans2, ans3)) << endl;
			}

		}
	}
}