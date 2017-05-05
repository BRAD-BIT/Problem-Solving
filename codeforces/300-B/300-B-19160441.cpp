//in the name of Allah
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
#define pr3(n)     cout<<fixed<<setprecision(4)<<n<<endl
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
const int MOD = 1e9 + 7;
using namespace std;
int nex[50], a[50], b[50], c[50], sze[50];
int found(int x)
{
	if (nex[x] == x) return x;
	else return nex[x] = found(nex[x]);
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i <= 49; i++)
		nex[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		nex[found(x)] = found(y);
	}
	for (int i = 1; i <= n; i++)
		sze[found(i)]++;
	for (int i = 1; i <= n; i++)
		if (sze[i]>3) { cout << -1; return 0; }
	a[0] = b[0] = c[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sze[i] == 2) a[++a[0]] = i;
		if (sze[i] == 1) b[++b[0]] = i;
	}
	if (a[0]>b[0]) { cout << -1; return 0; }
	int s = 0;
	for (int i = 1; i <= a[0]; i++) nex[b[i]] = a[i];
	for (int i = a[0] + 1; i <= b[0]; i += 3) nex[b[i + 1]] = nex[b[i + 2]] = b[i];
	for (int i = 1; i <= n; i++)
		if (i == found(i)) {
			for (int j = 1; j <= n; j++)
				if (found(j) == i) { printf("%d ", j); }

		}
	cout << endl;
}