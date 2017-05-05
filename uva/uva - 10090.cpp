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
const int MAX = 2e6 + 7;
const int MOD = 1e9 + 7;
int x, y, d;
void extendedEuclid(ll a, ll b) 
{
	if (b == 0) { x = 1; y = 0; d = a; return; }  
	extendedEuclid(b, a % b);
	ll x1 = y; 
	ll y1 = x - (a / b) * y; 
	x = x1;
	y = y1;
}/*
 2000000000
 1 2 
 1 4
 
 
 */
ll c1, c2;
void solve_extendedEuclid(ll a,ll b,ll c,ll n)
{
	extendedEuclid(a, b);
	if (c%d != 0) {
		cout << "failed\n";
		return;
	}
	ll low = ceil(-x*c / (ld)b), high = floor(y*c / (ld)a);
	if(low>high){
		cout << "failed\n";
		return;
	}
	//cout << high - low + 1 << endl;
	//lop(n_pos, low, low + 20)
		//cout << x*c / d + (b / d)*n_pos << " " << y*c / d - (a / d)*n_pos << endl;
	ll ans1 = x*c / d + (b / d)*low*c1 + y*c / d - (a / d) * low*c2;
	ll ans2 = x*c / d + (b / d)*high*c1 + y*c / d - (a / d) * high*c2;
	if (ans1 < ans2)
		cout << x*c / d + (b / d)*low << " " << y*c / d - (a / d) * low << endl;
	else cout << x*c / d + (b / d)*high << " " << y*c / d - (a / d) * high << endl;
}
int main()
{
	ll n, n1, n2;
	while ((cin >> n)&&n) {
		cin >> c1 >> n1 >> c2 >> n2;
		solve_extendedEuclid(n1, n2, n, 20);
	}
}