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
const int MAX = 1e3 + 7;
const int LEN = 250 + 7;
int MOD = 1e9 + 7;
ll NCR(ll n, ll r)
{
	int len = 0;
	if (r > n) return 0;
	if (r * 2 > n) r = n - r;
	if (r == 0) return 1;
	ll ans = n;
	lop(i, 2, r + 1) { ans *= (n - i + 1); ans /= i;}
	return ans;
}
int nCr[225][225][62];
void combination()
{
	lop(i, 1, 225){
		nCr[i][0][0] = 1; lop(j, 1, i+1) {
		lop(k, 0, 60) {
			nCr[i][j][k] += (nCr[i - 1][j][k] + nCr[i - 1][j - 1][k]);
			if (nCr[i][j][k] > 9)nCr[i][j][k + 1] = (nCr[i][j][k] / 10), nCr[i][j][k] %= 10;
		}
	}}
}
void print_ncr(int n, int k)
{
	int x=-1;
	loop(i, 60, 0)if (nCr[n][k][i]) { x = i; break; }
	if (x == -1) { cout << 0; return; }
	loop(i, x + 1, 0)cout << nCr[n][k][i];
}
int main()
{
	combination();
	//print_ncr(11, 5);
	int t; cin >> t;
	while (t--)
	{
		int n, m, black=0, white;
		cin >> n >> m;
		if (m == 0) { cout << 1 << endl; continue; }
		lop(i, 0, m)
		{
			int x; cin >> x; black += x;
		}
		white = n - black; if (white < m - 1) { cout << 0 << endl; continue; }
		print_ncr(white + 2, white - m + 1); cout << endl;
	}
}