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
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
#define loop(i,n,a)for(int i=n-1;i>=a;--i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define ll         long long
#define ld         long double
#define ii         pair<ld,ld>
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
int const MAX = 1000 + 7;
int const MOD = 1e9 + 7;
int arr[MAX];
int n, m, h;
ld nCr[MAX][MAX];
void combination(ll n)
{
    lop(i, 0, n)nCr[i][0] = 1, nCr[i][i] = 1;
    lop(i, 1, n)lop(j, 0, n)if (i != j)nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]);
}
ii mem[MAX][MAX][2];
ii dp(ll i, int sum, int team_mate)
{
    if (n == sum)if (team_mate)return ii(1, 1); else return ii(0, 1);
    if (sum>n || i == m)return ii(0, 0);
    if (mem[i][sum][team_mate].first >= 0)return mem[i][sum][team_mate];
    ii ans(0, 0);
    lop(k, 0, arr[i] + 1)
    {
        ii x = dp(i + 1, sum + k, team_mate | (i + 1 == h&&k));
        ld com = nCr[arr[i]][k]; x.first *= com; x.second *= com;
        ans.first += x.first;
        ans.second += x.second;
    }
    return mem[i][sum][team_mate] = ans;
}
int main()
{
    combination(MAX);
    lop(i, 0, MAX)lop(j, 0, MAX)lop(k, 0, 2)mem[i][j][k].first = -1;
    cin >> n >> m >> h;
    lop(i, 0, m)sc(arr[i]); arr[h - 1]--;
    ii out = dp(0, 1, 0);
    if (out.second == 0)cout << "-1\n"; else
        pr3(out.first / out.second);
}