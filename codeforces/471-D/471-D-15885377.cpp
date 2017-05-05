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
#define R_W        R_("in.txt"),W_("out.txt")
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
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
ll a[MAX], tmp[MAX];
void Z_Algrothim(int n,int m)
{
	vi Z(n,0);
	for(int i=1,L=0,R=0;i<n;i++)
	{
		if(i<=R)Z[i]=min(Z[i-L],R-i+1);
		while(i+Z[i]<n&&a[Z[i]]==a[i+Z[i]])Z[i]++;
		if(i+Z[i]-1>R)L=i,R=i+Z[i]-1;
	}
	int ans = 0;
	lop(i, m, n)if (Z[i] >= m-2)ans++;
	cout << ans << endl;
}
int main()
{
	int n, m; cin >> n >> m;
	lop(i, m+1, n+m+1)cin >> a[i];
	lop(i, m+1, n+m)a[i] -= a[i + 1];
	a[m] = -OO;
	lop(i, 0, m) { cin >> a[i]; tmp[i] = a[i]; }
	lop(i, 0, m - 1)a[i] -= a[i + 1];
	Z_Algrothim(n + m + 1, m+1);
}