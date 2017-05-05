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
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#include<string>
#include<cstdio>
using namespace std;
#define iter(it,S) for(set<int>::iterator it = S.begin(); it != S.end(); ++it)
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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1000 + 7;
int const MOD = 1e9 + 7;
struct t{ int h, m;};
int time_diff(t a,t b)
{
	int min = 0;
	while (!(a.h==b.h&&a.m==b.m))
	{
		if (a.m + 1 <= 59)a.m++;else if (a.h + 1 <= 12)a.m = 0, a.h++;else a.h = 1, a.m = 0;
		min++;
	}
	return min;
}
int main()
{
	//R_W;
	int T; sc(T); t arr[3];
	while (T--)
	{
		pair<ii, int>ans(ii(-1, -1), 0); map<ii, int>mp;
		lop(i, 0, 3){ cin >> arr[i].h; cin.ignore(); cin >> arr[i].m; }
		lop(k, 0, 3)lop(i, 0, 3)lop(j, 0, 3)if (i != j&&j != k)if (time_diff(arr[i], arr[k]) == time_diff(arr[k], arr[j]))
			if (time_diff(arr[i], arr[k]) <= 480 && time_diff(arr[i], arr[k]) != 0)
			ans.second += !mp[ii(arr[k].h, arr[k].m)], ans.first = ii(arr[k].h, arr[k].m), mp[ii(arr[k].h, arr[k].m)] = 1;
		mp.clear();
		if (ans.second != 1){ cout << "Look at the sun\n"; continue; }
		cout << "The correct time is " << ans.first.first << ":"; if (ans.first.second < 10)cout << 0; cout << ans.first.second << endl;
	}
}