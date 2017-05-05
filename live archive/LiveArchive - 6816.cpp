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
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 2000 + 7;
int const MOD = 1e9 + 7;
struct word{
	ld width, height, ocr; string s;
};
word arr[MAX];
int main()
{
	int W, N, T=1;
	while (1)
	{
		cin >> W >> N; if (W == 0)break;
		ld m = 0;
		lop(i, 0, N){ cin >> arr[i].s >> arr[i].ocr; m = max(m, arr[i].ocr); }
		lop(i, 0, N)
		{
			arr[i].height = (8 + ceil(40 * (arr[i].ocr - 4) / (m - 4)));
			arr[i].width = ceil(9.000 / 16.000 *arr[i].s.length()*arr[i].height);
		}
		int ans = 0;
		ld x = arr[0].width, y = arr[0].height;
		lop(i, 1, N)
		{
			if (x + arr[i].width+10 <= W)
			{
				x += arr[i].width+10; y = max(arr[i].height, y);
			}
			else
			{
				ans += y; y = 0; y = max(arr[i].height, y);
				x = arr[i].width;
			}
		}
		ans += y;
		cout << "CLOUD " << T++ << ": " << ans << endl;
	}
}