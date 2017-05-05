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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
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
int MOD = 1e9 + 7;
ll power_log(ll b, ll p){
	ll mul = b, ret = 1;
	while (p){
		if (p & 1)ret = (ret*mul);
		mul = (mul*mul);
		p >>= 1;
	}
	return ret;
}
vll arr;
map<pair<ii, ii>, int>mp;
void dp(int n2, int n3, int n5, int n7)
{
	if (mp.count(pair<ii, ii>(ii(n2, n3), ii(n5, n7))) == 1)return;
	mp[pair<ii, ii>(ii(n2, n3), ii(n5, n7))] = 1;
	ll n = power_log(2, n2)*power_log(3, n3)*power_log(5, n5)*power_log(7, n7);
	if (n > 2000000000)return;
	arr.push_back(n);
	dp(n2+1, n3, n5, n7);
	dp(n2, n3+1, n5, n7);
	dp(n2, n3, n5+1, n7);
	dp(n2, n3, n5, n7+1);
}
int main()
{
	dp(0, 0, 0, 0);
	sort(all(arr));
	int n;
	while ((cin >> n) && n)
	{
		printf("The %d", n);
		if (n % 10 == 1 && (n / 10) % 10 != 1) printf("st");
		else if (n % 10 == 2 && (n / 10) % 10 != 1) printf("nd");
		else if (n % 10 == 3 && (n / 10) % 10 != 1) printf("rd");
		else printf("th");
		printf(" humble number is %lld.\n", arr[n - 1]);
	}
}