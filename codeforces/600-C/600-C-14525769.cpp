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
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int o[26];
int main()
{
    string s; cin >> s;
    int n = s.length() % 2, m = 0;
    lop(i, 0, s.length())o[s[i] - 'a']++;
    lop(i, 0, 26)m += o[i] % 2;
    lop(i, 0, 26)
    {
        if (o[i] % 2 == 0 || m <= 1)continue;
        o[i]++; m -= 2;
        loop(j, 26,i+1 )if (o[j] % 2 == 1) { o[j]--; break; }
    }
    int x = 0; char odd;
    lop(i, 0, s.length())s[i] = '#';
    lop(i, 0, 26)
    {
        lop(j, 0, o[i]/2)cout << char('a' + i);
        if(o[i] % 2)odd = char('a' + i);;
    }
    if(n)cout << odd;
    loop(i, 26, 0)
    {
        lop(j, 0, o[i] / 2)cout << char('a' + i);
    }
    cout << endl;
}