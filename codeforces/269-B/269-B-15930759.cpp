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
const int MAX = 100 + 7;
const int MOD = 1e9 + 7;
vi a;
int  LIS(vi arr)
{
	vi c(sz(arr) + 1), dp(sz(arr));
	int len = 1;
	dp[0] = 1, c[1] = arr[0];
	lop(i, 1, sz(arr))
	{
		if (arr[i] < c[1])c[1] = arr[i], dp[i] = 1;
		else if (arr[i] >= c[len])dp[i] = ++len, c[len] = arr[i];
			else{
				int s = 1, e = len, mid, k = -1;
				while (s <= e){
					mid = (s + e) / 2;
					if (arr[i] <= c[mid]){
						if (c[mid - 1] <= arr[i] && arr[i] <= c[mid])
							k = mid, s = mid + 1;
						else e = mid - 1;}
					else if (arr[i] > c[mid]) s = mid + 1;}
				if (k == -1) {
					dp[i] = 1;
					continue;
				}
				c[k] = arr[i];
				dp[i] = k;
			}
	}
	return len;
}
int main()
{
	int n, m; sc(n), sc(m);
	lop(i, 0, n) {
		ld x, y; cin >> x >> y;
		a.push_back(x);
	}
	cout << n-LIS(a) << endl;
}