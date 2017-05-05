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
//#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<string>
#include<cstdio>
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
#define pr3(n)     cout<<fixed<<setprecision(2)<<n
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 200 + 7;
int const MOD = 1e9 + 7;
ld p[2][16]; ld a[20][20]; string s[20];
void solve()
{
	for (int x = 2; x <= 16; x *= 2)
	{
	    for (int y = 0; y < 16; y += x)
		lop(i,y,y+x)
		{ld ans = 0;
		lop(j, y, y + x)if ((i < y + x / 2 && j >= y + x / 2) || (i >= y + x / 2 && j < y + x / 2)){
		if (x == 2)ans = a[i][j]; else ans += p[0][i] * p[0][j] * a[i][j];}p[1][i] = ans;}
		lop(i, 0, 16)p[0][i] = p[1][i];
	}
}
int main()
{
	int m = 0;
	lop(i, 0, 16){ cin >> s[i]; m = max(m, int(s[i].length())); }
	m++;
	lop(i, 0, 16)lop(j, 0, 16){ cin >> a[i][j]; a[i][j] /= 100.00; }
	solve();
	lop(i, 0, 16)
	{
		cout << s[i];
		lop(j, s[i].length(), m)cout << " ";
		cout << "p="; pr3(p[1][i] * 100);cout << "%\n";
	}
}