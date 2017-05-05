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
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
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
const int MAX = 300 + 7;
const int MOD = 1e9 + 7;
vs s1, s2;
int mem[MAX][MAX];
int LCS(int i, int j)
{
	if (i == sz(s1) || j == sz(s2))return 0;
	if (mem[i][j] != -1)return mem[i][j];
	if (s1[i] == s2[j])return  mem[i][j]=LCS(i + 1, j + 1) + 1;
	return  mem[i][j]=max(LCS(i, j + 1), LCS(i + 1, j));
}
void print_LCS()
{
	vs ans;
	memset(mem, -1, sizeof mem);
	LCS(0, 0);
	int i = 0, j = 0;
	while (i < sz(s1) && j < sz(s2))
	{
		if (s1[i] == s2[j]) { ans.push_back(s1[i]); i++, j++; }
		else
			if (mem[i + 1][j] > mem[i][j + 1])i++;
			else j++;
	}
	lop(i, 0, sz(ans)) { if (i == 0)cout << ans[i]; else cout << " " << ans[i]; }
	cout << endl;
}
int main()
{
	int i = 0, x=0; string temp;
	while (cin >> temp)
	{
		if (temp == "#")
		{
			if (i == 1)
			{
				print_LCS();
				s1.clear(), s2.clear();
				i = 0;
			}
			else i = 1;
			continue;
		}
		if (i == 0)s1.push_back(temp);
		else s2.push_back(temp);
	}
}