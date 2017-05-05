//In the name of Allah
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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
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
const int MAX = 1e4 + 7;
const int MOD = 1e9 + 7;
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }
int prefix_gcd[MAX], arr[MAX], temp[MAX], f[MAX];
map<int, int>bad_prime;
int fun(int num)
{
	int f = 0;
	for (int i = 2; i*i <= num; i++)
	{
		while (num%i == 0)
		{
			if (bad_prime[i])f--;
			else f++;
			num /= i;
		}
	}
	if (num > 1)if (bad_prime[num])f--; else f++;
	return f;
}
int main()
{	
	int n, m, ans = 0;
	cin >> n >> m;
	sc(arr[0]); prefix_gcd[0] = arr[0];
	lop(i, 1, n) { sc(arr[i]); prefix_gcd[i] = gcd(prefix_gcd[i - 1], arr[i]); }
	lop(i, 0, m) { int x; sc(x); bad_prime[x]++; }
	loop(i, n + 1, 0)if (fun(prefix_gcd[i]) < 0)lop(j, 0, i + 1) { arr[j] /= prefix_gcd[i]; prefix_gcd[j] /= prefix_gcd[i]; }
	lop(i, 0, n)ans += fun(arr[i]);
	cout << ans << endl;
}