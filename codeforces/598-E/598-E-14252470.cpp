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
#define R_W        R_("easy.in"),W_("easy.out")
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
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 50 + 7;
int dp[MAX][MAX][MAX];
int solve(int r, int c,int k)
{
    if (r*c == k||k==0)return dp[r][c][k]=0;
    if (r*c < k)return dp[r][c][k] = oo;
    if (dp[r][c][k] != -1)return dp[r][c][k];
    dp[r][c][k] = oo;
    lop(u, 0, k+1)
    {
        lop(i, 1, r)
        {
            dp[r][c][k] = min(dp[r][c][k], solve(i, c, u) + solve(r - i, c, k - u) + c*c);
        }
        lop(i, 1, c)
        {
            dp[r][c][k] = min(dp[r][c][k], solve(r, i, u) + solve(r, c - i, k - u) + r*r);
        }
    }
    return dp[r][c][k];
}
int main()
{

    memset(dp, -1, sizeof dp);
    solve(33, 33, 55);
    int t; cin >> t;
    while (t--)
    {
        int r, c, k; cin >> r >> c >> k;
        cout << dp[r][c][k] << endl;
    }
}