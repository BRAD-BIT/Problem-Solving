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
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
ii s[MAX]; vi a;
int main()
{
	R_W;
	int n, ans = oo, zero = 0, xt = 0; cin >> n;
	lop(i, 0, n) {
		int x; sc(x); a.push_back(x); 
	}
	if (a[0] > 0)xt++, a[0] = -1;
	if (a[n - 1] < 0)xt++, a[n-1] = 1;
	loop(i, sz(a), 0) {
		s[i].first = (a[i] < 0);
		if (i != sz(a) - 1)
			s[i].first += s[i + 1].first;
		zero += (a[i] == 0);
	}
	lop(i, 0, sz(a))
	{
		s[i].second= (a[i] > 0);
		if (i)s[i].second += s[i - 1].second;
	}
	lop(i, 1, n-1)
	{
		int x = s[i].second - (a[i] > 0);
		int y = s[i].first - (a[i] < 0);
		ans = min(ans, x + y);
	}
	if (n == 2)ans = 0;
	cout << ans + xt + zero << endl;
}