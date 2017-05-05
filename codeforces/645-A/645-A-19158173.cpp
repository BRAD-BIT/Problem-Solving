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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
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
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }
ii nex(ii x)
{
	if (x.first == 0 && x.second == 0)return ii(1, 0);
	if (x.first == 1 && x.second == 0)return ii(1, 1);
	if (x.first == 0 && x.second == 1)return ii(0, 0);
	if (x.first == 1 && x.second == 1)return ii(0, 1);
}
int main()
{	
	char a[2][2], b[2][2];
	ii x1, x2;
	lop(i, 0, 2)lop(j, 0, 2) { cin >> a[i][j]; if (a[i][j] == 'A')x1 = ii(i, j); }
	lop(i, 0, 2)lop(j, 0, 2) { cin >> b[i][j]; if (b[i][j] == 'A')x2 = ii(i, j); }
	string s1="A", s2="A";
	lop(i, 0, 3) 
	{
		if (a[nex(x1).first][nex(x1).second] != 'X') { s1 += a[nex(x1).first][nex(x1).second];  }x1 = nex(x1);
		if (b[nex(x2).first][nex(x2).second] != 'X') { s2 += b[nex(x2).first][nex(x2).second]; }x2 = nex(x2);
	}
	//cout << s1 << endl << s2 << endl;
	if (s1 == s2)cout << "YES\n";
	else cout << "NO\n";
}