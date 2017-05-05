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
int const MAX = 1000 + 7;
int const MOD = 1e9 + 9;
using namespace std;

#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define ll long long
#define ull unsigned long long
#define lop(i,n) for(int i=0;i<n;++i)

typedef pair<ll,ll>  pll;

ull gcd(ull a,ull b){
    return (!b? a : gcd(b,a%b));
}
ull mn(ull a,ull b){
    if(a<b)return a;
    return b;
}
int main(){
    ull t,a,b,o=1;
    double td,ad,bd;
    cin>>t>>a>>b;
    td=t,ad=a,bd=b;
    if(ad/gcd(a,b)>td/bd){
        ull res=mn(t,mn(a,b)-1);
        cout<<res/gcd(res,t)<<"/"<<t/gcd(res,t);
        return 0;
    }
    ull lcm=(a/gcd(a,b) )* b;
    ull x=t/lcm;
    ll out=0;
    if(x)out=mn(a,b)-1,out+=(x-1)*mn(a,b);
    if(t>=(x*lcm+mn(a,b))-o)out+=mn(a,b);
    else out+=t-x*lcm+1;
    cout<<out/gcd(out,t)<<"/"<<t/gcd(out,t);
}