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
#define loop(i,n,a)for(int i=n;i>=a;--i)
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
#define pr3(n)     cout<<fixed<<setprecision(4)<<n<<endl
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
const int MAX = 4 * 1e5 + 7;
string del(string s)
{
    string ss;
    lop(i, 0, s.length())if (s[i] != '_'&&s[i] != '-'&&s[i] != ';')ss += tolower(s[i]);
    return ss;
}
int main()
{
    string s[3]; cin >> s[0] >> s[1] >> s[2];
    s[0] = del(s[0]), s[1] = del(s[1]), s[2] = del(s[2]);
    vs ss;
    lop(i, 0, 3)lop(j, 0, 3)lop(k, 0, 3)if (i != j&&j != k&&i != k)ss.push_back(s[i] + s[j] + s[k]);
    int n; cin >> n;
    lop(i, 0, n)
    {
        cin >> s[0]; s[0] = del(s[0]);
        lop(j, 0, sz(ss))if (s[0] == ss[j]){ cout << "ACC\n"; goto NEXT; }
        cout << "WA\n";
    NEXT:;
    }
}