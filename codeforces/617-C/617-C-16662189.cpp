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
const int MAX = 2000 + 7;
const int MOD = 1e9 + 7;
ii p[MAX];
ll r1[MAX];
int main()
{
	int n; ii p1, p2;
	cin >> n >> p1.first >> p1.second >> p2.first >> p2.second;
	lop(i, 0, n)
	{
		cin >> p[i].first >> p[i].second;
		r1[i + 1] = (p1.first - p[i].first)*(p1.first - p[i].first) + (p1.second - p[i].second)*(p1.second - p[i].second);
	}
	ll ans = OO;
	lop(i, 0, n+1)
	{
		ll r2=0;
		lop(j, 0, n)
		{
			ll temp= (p1.first - p[j].first)*(p1.first - p[j].first) + (p1.second - p[j].second)*(p1.second - p[j].second);
			if (temp > r1[i])
			{
				r2 = max(r2, (p2.first - p[j].first)*(p2.first - p[j].first) + (p2.second - p[j].second)*(p2.second - p[j].second));
			}
		}
		ans = min(ans, r1[i] + r2);
	}
	cout << ans << endl;
}