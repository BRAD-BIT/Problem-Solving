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
int arr[MAX], k;
int binary(int i)
{
	int start = 1, end = i, mid, ans1 = -1, ans2 = -1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[i] - arr[mid - 1] == k)
			start = mid + 1, ans1 = mid;
		else
			if (arr[i] - arr[mid - 1] < k)
				end = mid - 1;
			else
				if (arr[i] - arr[mid - 1] > k)
					start = mid + 1;
	}
	start = 1, end = i, mid, ans2 = -1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[i] - arr[mid - 1] == k)
			end = mid - 1, ans2 = mid;
		else
			if (arr[i] - arr[mid - 1] < k)
				end = mid - 1;
			else
				if (arr[i] - arr[mid - 1] > k)
					start = mid + 1;
	}
	return (ans1 - ans2 + 1)*(ans1 != -1);
}
int main()
{
	 sc(k);
	string s; cin >> s;
	lop(i, 0, s.length())
	{
		arr[i + 1] += (arr[i] + (s[i] == '1'));
	}
	ll ans = 0;
	lop(i, 1, s.length() + 1)
	{
		if (arr[i] >= k)
			ans += binary(i);
	}
	cout << ans << endl;
}