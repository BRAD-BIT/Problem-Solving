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

#define lop(i,n)   for(ll i=0;i<n;++i)
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
#define clr(a,b)   memset(a,b,sizeof a)
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
ll mod = 1e9 + 7;
const int MAX = 10000 + 7;
struct point{ int x, y; point(int v = 0, int g = 0) :x(v), y(g){} }; int arr[MAX];
point p[MAX]; char ans[MAX][MAX];
int main()
{
    int n; sc(n); ii xx(0, -oo), yy(0, -oo);
    lop(i, n)
    {
        int a, x = 0, y = 0; sc(a); arr[i] = a;
        if ((i + 1) % 2 == 0)y = -a; else y = a; x = a;
        p[i + 1].x = p[i].x + x, p[i + 1].y = p[i].y + y;
        xx.first = min(int(xx.first), p[i + 1].x);
        xx.second = max(int(xx.second), p[i + 1].x);

        yy.first = min(int(yy.first), p[i + 1].y);
        yy.second = max(int(yy.second), p[i + 1].y);
    }
    clr(ans, ' ');
    /*op(i, n)p[i+1].x, p[i + 1].y--;*/
    ii last(0, 0);
    lop(i, n)
    {
        int x =p[i].x, y =last.second; int dx=1, dy = 1;
        if (p[i + 1].y < p[i].y)dy = -1;
        lop(j, arr[i])
        {
            int c = x+j*(dx) - xx.first;

            int r = abs(yy.first - yy.second) - (y+j*(dy) - yy.first)-1;
            if (dy==1)ans[r][c] = '/'; else ans[r][c] = '\\';
            last=ii(x + j*dx, y + j*dy);
        }
    }
    lop(i, abs(yy.second-yy.first)){ lop(j, abs(xx.second-xx.first))cout << ans[i][j]; cout << endl; }
}