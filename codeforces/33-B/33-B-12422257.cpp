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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 200 + 7;
ll G[26][26];
void floyd()
{
    lop(i, 0, 26)lop(j, 0, 26){ if (i == j)G[i][j] = 0;else G[i][j] = oo; } int n; cin >> n;
    lop(i, 0, n)
    {
        char a, b; ll c; cin >> a >> b >> c; G[a - 'a'][b - 'a'] = min(c, G[a - 'a'][b - 'a']);
    }
    lop(k, 0, 26)lop(i, 0, 26)lop(j, 0, 26)G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
int main()
{
    string s1, s2, s3; cin >> s1 >> s2; s3 = s1;
    if (s1.length() != s2.length())return(cout << "-1\n", 0);
    floyd();
    ll ans = 0; 
    lop(i, 0, s1.length())
    {
        ll m = oo;
        lop(j, 0, 26)
            if (G[s1[i] - 'a'][j] + G[s2[i] - 'a'][j] < m)m = G[s1[i] - 'a'][j] + G[s2[i] - 'a'][j], s3[i] = char('a' + j);
        ans += m;
    }
    if (ans < oo)cout << ans << endl << s3 << endl; else cout << "-1\n";
}