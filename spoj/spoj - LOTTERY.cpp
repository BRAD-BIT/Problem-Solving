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
	vi FT;
	Fenwick_Tree(int n)
	{
		FT.resize(n + 1, 0);
	}
	int LSOne(int x)
	{
		return x&-x;
	}
	int RSQ(int b)
	{
		if (b <= 0)return 0;
		return FT[b] + RSQ(b - LSOne(b));
	}
	int RSQ(int a, int b)
	{
		return RSQ(b) - RSQ(a - 1);
	}
	void update(int i, int v)
	{
		if (i >= sz(FT))return;
		FT[i] += v; update(i + LSOne(i), v);
	}
	int get(int v)
	{
		int s = 1, e = sz(FT) - 1, mid, ans = -1;
		while (s <= e)
		{
			mid = (s + e) / 2;
			int sum = RSQ(mid);
			if (sum > v)e = mid - 1;
			if (sum < v)s = mid + 1;
			if (sum == v) { ans = mid; e = mid - 1; }
		}
		return ans;
	}

};
bool comp(ii a, ii b)
{
	return a.second < b.second;
}
vii num;
map<int, int>mp;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		
		int n, k;
		sc(n), sc(k);
		Fenwick_Tree FT(n+2);
		lop(i, 0, n)
		{
			int m; sc(m);
			num.push_back(ii(m, i));
		}
		sort(all(num));
		lop(i, 0, n)if (num[i].first != 0)mp[i] = num[i].first,num[i].first = i;
		else num[i].first = -1;
		sort(all(num), comp);
		lop(i, 0, n)
		{
			if (num[i].first != -1)
			{
				FT.update(num[i].first + 1, 1);
			}
			else
			{
				int ans = FT.get(k);
				if (ans != -1)ans = mp[ans-1];
				cout << ans << endl;
			}
		}
		mp.clear(), num.clear();
	}
}