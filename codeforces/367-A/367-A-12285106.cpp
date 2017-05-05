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
const int MAX = 1e5 + 7;
struct ch{ int x, y, z; ch(){ x = 0; y = 0; z = 0; } };
ch sum[MAX];
int main()
{
    string s; cin >> s;
    lop(i, s.length())
    {
        sum[i].x = (s[i] == 'x'), sum[i].y = (s[i] == 'y'), sum[i].z = (s[i] == 'z');
        if (i){ sum[i].x += sum[i - 1].x, sum[i].y += sum[i - 1].y, sum[i].z += sum[i - 1].z; }
    }
    int q; cin >> q;
    lop(i, q)
    {
        int a, b; cin >> a >> b; a--, b--;
        int x = sum[b].x - sum[a].x + (s[a] == 'x');
        int y = sum[b].y - sum[a].y + (s[a] == 'y');
        int z = sum[b].z - sum[a].z + (s[a] == 'z');
        int l = b - a + 1;
        if (l<3)
            cout << "YES\n";
        else
        if (l % 3 == 0)
            if ((x == y&&y == z))cout << "YES\n"; else cout << "NO\n";
        else
        if (l % 3 == 1)
            if ((x == y&&x == z - 1) || (x == z&&x == y - 1) || (y == z&&z == x - 1))
                cout << "YES\n"; else cout << "NO\n";
        else
        if (l % 3 == 2)
            if ((x == y&&x == z + 1) || (x == z&&x == y + 1) || (y == z&&z == x + 1))
                cout << "YES\n"; else cout << "NO\n";

    }
}