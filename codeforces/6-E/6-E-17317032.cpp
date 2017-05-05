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
int arr[MAX], k;
struct node
{
	int MAX, MIN, num; 
	node(int x, int y, int z) :MAX(y), MIN(x), num(z) {};
};
class Segment_Tree
{
public:
	vii ST; int s, e;
	Segment_Tree(int n)
	{
		ST.resize(4 * n, ii(oo, -oo));
	}
	void bulid(int p, int l, int r)
	{
		if (l == r) { ST[p] = ii(arr[l], arr[l]); return; }
		int mid = (l + r) / 2;
		bulid(2 * p, l, mid);
		bulid(2 * p + 1, mid + 1, r);
		ST[p] = ii(min(ST[2 * p].first, ST[2 * p + 1].first), max(ST[2 * p].second, ST[2 * p + 1].second));
	}
	ii merge(ii a, ii b)
	{
		return ii(min(a.first, b.first), max(a.second, b.second));
	}
	ii get(int p, int l, int r)
	{
		if (s > r || e < l)return ii(oo, -oo);
		if (s <= l&&e >= r)return ST[p];
		int mid = (l + r) / 2;
		return merge(get(2 * p, l, mid), get(2 * p + 1, mid + 1, r));
	}
	bool can(int S, int E,int n)
	{
		s = S, e = E;
		ii rt = get(1, 0, n - 1);
		return (rt.second - rt.first  <= k);
	}
};
map<int, int>mp;
vii ans;
int main()
{
	int n; cin >> n >> k;
	Segment_Tree ST(n);
	lop(i, 0, n)scl(arr[i]);
	ST.bulid(1, 0, n - 1);
	ll ma = -oo;
	lop(i, 0, n)
	{
		int start = i, end = n - 1, mid, e;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (ST.can(i, mid, n))e= mid, start = mid + 1;
			else end = mid - 1;
		}
		ma = max(e - i + 1, ma);
		mp[e - i + 1]++;
		ans.push_back(ii(i, e));
	}
	cout << ma << " " << mp[ma] << endl;
	lop(i, 0, sz(ans))if (ans[i].second - ans[i].first + 1 == ma)cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
}