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

#define lop(i,n)   for(int i=0;i<n;++i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define ld         long double
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;

int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
char s1[200010];
char s2[200010];
bool eq(int f1,int t1,int f2,int t2)
{
    int flag = 1;
    for (int i = f1, j = f2; i <= t1&&j <= t2; ++i, ++j)if (s1[i] != s2[j]){ flag = 0; break; }


    if (flag)return 1;
    int n = t1-f1+1;
    if (n==0 || n % 2 != 0)return 0;
    int mid1 = (f1 + t1) / 2, mid2 = (f2 + t2) / 2;
    return ( (eq(f1, mid1, f2, mid2)&& eq(mid1 + 1, t1, mid2 + 1, t2) ) 
        ||
              (eq(f1, mid1, mid2 + 1, t2) && eq(mid1 + 1, t1, f2, mid2)) );
}
int main()
{
    scanf("%s", &s1);
    scanf("%s", &s2);
    int n = strlen(s1);
    if (eq(0,n-1,0,n-1))cout << "YES\n"; else cout << "NO\n";
}