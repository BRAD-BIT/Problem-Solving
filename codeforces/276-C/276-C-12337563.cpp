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
#define scl(n)     scanf("%lld",&n)
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
const int MAX = 4*1e5 + 7;
ll arr[MAX], times[MAX]; int f, t;
class SegmentTree
{
public:
    vll ST, mixed;
    SegmentTree(int n){ ST.resize(4 * n, 0); mixed.resize(4 * n, 0); }
    void qurey(int p, int s, int e)
    {
        if (f > e || t < s)return;
        if (f <= s&&e <= t)
        {ST[p]++; return;}
        if (mixed[p]==0)ST[2 * p] = ST[2 * p + 1] = ST[p];
        else ST[2 * p] += ST[p], ST[2 * p + 1] += ST[p];
        int mid = (s + e) / 2;
        qurey(2 * p, s, mid);
        qurey(2 * p + 1, mid + 1, e);
        mixed[p] = mixed[2 * p]==1 | mixed[2 * p + 1]==1 | ST[2 * p] != ST[2 * p + 1];
        if (mixed[p]==1)ST[p] = 0, mixed[p] = 1;
        else ST[p] = ST[2 * p];
    }
    void update(int p, int s, int e)
    {
        if (s == e){ times[s] = ST[p]; return; }
        if (mixed[p] == 0)ST[2 * p] = ST[2 * p + 1] = ST[p];
        else ST[2 * p] += ST[p], ST[2 * p + 1] += ST[p];
        int mid = (s + e) / 2;
        update(2 * p, s, mid);
        update(2 * p + 1, mid + 1, e);
    }
};
int main()
{
    int n, q; sc(n), sc(q); SegmentTree ST(n);
    lop(i, n)scl(arr[i]);
    lop(i, q)
    {
        sc(f), sc(t); f--, t--;
        ST.qurey(1, 0, n - 1);
    }
    ST.update(1, 0, n - 1);
    sort(arr, arr + n);
    sort(times, times + n);
    unsigned long long ans = 0;
    lop(i, n)ans += (times[i] * arr[i]);
    cout << ans << endl;
}