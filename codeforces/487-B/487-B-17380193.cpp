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
ll arr[MAX], dp[MAX], longest[MAX], L, D;
struct node
{
	ll MAX, MIN, num;
	node(ll x, ll y, ll z) :MAX(y), MIN(x), num(z) {};
};
class Segment_Tree
{
public:
	vii ST; int s, e;
	Segment_Tree(int n)
	{
		ST.resize(4 * n, ii(OO, -OO));
	}
	void bulid(int p, int l, int r)
	{
		if (l == r) { ST[p] = ii(arr[l], arr[l]); return; }
		int mid = (l + r) / 2;
		bulid(2 * p, l, mid);
		bulid(2 * p + 1, mid + 1, r);
		ST[p] = merge(ST[2 * p], ST[2 * p + 1]);
	}
	ii merge(ii a, ii b)
	{
		return ii(min(a.first, b.first), max(a.second, b.second));
	}
	ii get(int p, int l, int r)
	{
		if (s > r || e < l)return ii(OO, -OO);
		if (s <= l&&e >= r)return ST[p];
		int mid = (l + r) / 2;
		return merge(get(2 * p, l, mid), get(2 * p + 1, mid + 1, r));
	}
	void insert(int p, int l, int r, int i, ll v)
	{
		if (l == r) { ST[p] = ii(v, v); return; }
		int mid = (l + r) / 2;
		if (mid >= i)insert(2 * p, l, mid, i, v);
		else insert(2 * p + 1, mid + 1, r, i, v);
		ST[p] = merge(ST[2 * p], ST[2 * p + 1]);
	}
	bool can(int S, int E, int n)
	{
		if (E - S + 1 < L)return 0;
		s = S, e = E;
		ii rt = get(1, 0, n - 1);
		return (rt.second - rt.first <= D);
	}
};
int main()
{
	int n; sc(n); scl(D); scl(L);
	lop(i, 0, n)scl(arr[i]);
	Segment_Tree ST(n);
	ST.bulid(1, 0, n - 1);
	lop(i, 0, n)
	{
		int s = 0, e = i - L + 1, mid, ans = 0;
		while (s <= e)
		{
			mid = (s + e) >> 1;
			if (ST.can(mid, i, n))ans = i - mid + 1, e = mid - 1;
			else s = mid + 1;
		}
		longest[i] = ans;
	}

	//lop(i, 0, n)cout << longest[i] << " "; cout << endl;
	int j = 0;
	lop(i, 0, L - 1) { dp[i] = OO; ST.insert(1, 0, n - 1, i, dp[i]);}
	lop(i, L - 1, n)if (longest[i] == 0) { dp[i] == OO; ST.insert(1, 0, n - 1, i, dp[i]);}
	else {
		if (longest[i] != i + 1)return(cout << "-1", 0);
		else { dp[i] = 1; j = i + 1; ST.insert(1, 0, n - 1, i, dp[i]); break; }
	}
	lop(i, j, n)
	{
		if (longest[i] != i + 1)
		{
			ST.s = i - longest[i]; ST.e = i - L;
			if (ST.e >= ST.s)
				dp[i] = ST.get(1, 0, n - 1).first + 1;
			else dp[i] = OO;
		}
		else
		{
			dp[i] = 1;
		}
		ST.insert(1, 0, n - 1, i, dp[i]);
	}
	if(dp[n-1]>=OO)return(cout << "-1", 0);
	cout << dp[n-1] << endl;
}