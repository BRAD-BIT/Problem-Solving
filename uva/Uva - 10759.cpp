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
//#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
using namespace std;
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
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
ll al, n, x; ll mem[30][200];
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }
ll dp(int i, ll sum)
{
	if (i == n)
	{
		if (sum >= x)return 1; else return 0;
	}
	if (mem[i][sum]!=-1)return mem[i][sum];
	ll ans = 0;
	lop(k, 0, 6)ans += dp(i + 1, sum + k + 1);
	return mem[i][sum] = ans;
}
int main()
{
	while (1)
	{
		cin >> n >> x; if (n == 0 && x == 0)return 0;
		memset(mem, -1, sizeof mem); al = pow(6,n);
		ll event = dp(0, 0);
		ll space = pow(6, n);
		ll com = gcd(event, space);
		event /= com, space /= com;
		if (event%space!=0)
		cout << to_string(event) << "/"<<to_string(space) << endl;
		else cout << to_string(event / space) << endl;
	}
}