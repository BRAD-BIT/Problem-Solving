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
int f[MAX], fenv[MAX], a[MAX], x, n, m, sz, allS, d;
void add(int x, int d) {
	while (x <= 1000000) {
		fenv[x] += d;
		x = x | (x + 1);
	}
}
int gett(int x) {
	int d = 0;
	while (x > 0) {
		d += fenv[x];
		x = x & (x + 1);
		x -= 1;
	}
	return d;
}
int get(int x) {
	int l, r;
	l = 0;
	r = sz;
	while (l + 1 < r) {
		int c = (l + r) / 2;
		if (gett(c) >= x) r = c;
		else l = c;
	}
	return r;
}
void del(int d) {
	int u = get(d);
	add(u, -1);
}
int main() 
{
	cin >> n >> m;
	lop(i, 0, m) cin >> a[i];
	while(n--)
	{
		cin >> x;
		if (x == -1) 
		{
			lop(j,0,m)
			{
				int d = a[j] - j;
				if (d > allS) break;
				del(d);--allS;
			}
		}
		else 
		{
			++sz;++allS;f[sz] = x;
			add(sz, 1);
		}
	}
	if (allS == 0) cout << "Poor stack!" << endl;
	else 
	{
		lop(i,1,allS+1)
		{
			int r = f[get(i)];
			cout << r;
		}
		cout << endl;
	}
}