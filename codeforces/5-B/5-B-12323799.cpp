//WINTER IS COMING.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<numeric>
using namespace std;

#define all(v)         v.begin(),v.end()
#define sz(V)        ((ll)((v).size()))
#define pp(x)               push_back(x)
#define ck(a)               (a<1 || a>9)
#define lop(i,n)    for(ll i=0;i<n;i++)
#define loop(i,f,l) for(ll i=f;i<l;i++)
#define READ(s)   freopen(s, "r", stdin)
#define WRITE(s) freopen(s, "w", stdout)
#define scl(n)          scanf("%lld",&n)
#define sc(n)             scanf("%d",&n)
#define INF                   1000000000000000000
#define PI             3.141592653589793
#define print(v)      lop(i, v.size()) cout<<v[i]<<" ";
#define read(v)   lop(i, v.size()) cin>>v[i];
#define printll(x)  printf("%lld", x);
#define scand(x) scanf("%lf", &x);
#define printd(x) printf("%f", x);
typedef string            ss;
typedef long long         ll;
typedef pair <ll, ll>   ii;
typedef pair<string, ll> si;
typedef pair<ll, string> is;
typedef pair<char, ll>  chi;
typedef vector<ii>       vii;
typedef vector<ll>       vi;
typedef vector<vi>       vvi;
typedef vector<string>    vs;
typedef vector<ll>       vll;
//WRITE("output.txt");
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }
ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll sd(ll x){ return x < 10 ? x : x % 10 + sd(x / 10); }
double sq(double x){ lop(i, x)if ((double)i*i > x) return (i - 1); return double(1); }

int main()
{
    int m = 0;string s;vector<string>v;
    while (getline(cin, s))
    {
        m = max(int(s.length()), m);
        v.push_back(s);
    };
    cout << string(m + 2, '*') << endl;
    for (int i = 0, j = 1; i<v.size(); ++i)
    {
        int w = m - v[i].length();
        if (w % 2){++j;};
        cout << '*' << string(w / 2 + (w % 2)*(j % 2), ' ') << v[i] 
            << string(m - w / 2 - v[i].length() - (w % 2)*(j % 2), ' ') << "*\n";
    };
    cout << string(m + 2, '*') << endl;
}