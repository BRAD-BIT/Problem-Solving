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
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
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
int const MAX = 1e6 + 7;
int const MOD = 1000000007;
struct line { int k, d, s1, s2; };
line a[MAX]; int n, x1, x2;
bool comp1(line a, line b) { return a.s1 < b.s1; }
bool comp2(line a, line b) { return a.s2 < b.s2; }
bool is_intersected(line a, line b)
{
    if (a.k == b.k)return 0;
    if (a.k < b.k)swap(a, b);
    ld x= x = ld(b.d - a.d) / ld(a.k - b.k);
    return (x > x1&&x < x2);
}
int main()
{
    cin >> n >> x1 >> x2;
    lop(i, 0, n)
    { 
        cin >> a[i].k >> a[i].d; a[i].s1 = a[i].k*x1 + a[i].d; a[i].s2 = a[i].k*x2 + a[i].d;
    }
    sort(a, a + n, comp1);
    lop(i, 0, n - 1)
    {
        if (is_intersected(a[i], a[i + 1]))return(cout << "YES\n", 0);
    }
    sort(a, a + n, comp2);
    lop(i, 0, n - 1)
    {
        if (is_intersected(a[i], a[i + 1]))return(cout << "YES\n", 0);
    }
    cout << "NO\n";
}