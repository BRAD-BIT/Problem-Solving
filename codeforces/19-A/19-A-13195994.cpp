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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS 1e-9
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
 map<string,int>mp1,mp2,mp3;
int main()
{
   int n,a,b; sc(n);string s,t; char ch;vs ss(n/2);
    vector<pair<ii,pair<int,string>>>v(n);
    lop(i,0,n)cin>>v[i].second.second;
    for(int i=0; i<n*(n-1)/2; ++i)
    {
        cin>>s>>a>>ch>>b; 
        t=s.substr(s.find('-')+1);
        s=s.substr(0,s.find('-'));
        if(a<b)mp1[t]+=3;else if(a>b)mp1[s]+=3;else mp1[s]++,mp1[t]++;
         mp2[s]+=a;mp2[t]+=b;
         mp3[s]+=a,mp3[s]-=b;
         mp3[t]+=b,mp3[t]-=a;
    }
    lop(i,0,n)
    {
        v[i].first.first=mp1[v[i].second.second];
        v[i].first.second=mp3[v[i].second.second];
        v[i].second.first=mp2[v[i].second.second];
    }
    sort(all(v));reverse(all(v));
   lop(i,0,n/2)ss[i]=v[i].second.second;
   sort(all(ss));
   lop(i,0,n/2)cout<<ss[i]<<endl;

}