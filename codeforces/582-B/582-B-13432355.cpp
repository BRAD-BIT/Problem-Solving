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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n
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
vi a;int ocr[333],MX=0,n,t;
void LIS() {
    int n = a.size();
    vi res(n), dp(n + 1, 500);
    dp[0] = -1;
    for (int i = 0; i < n; ++i) {
            res[i] = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[ res[i] ] = a[i];
    }
    cout<<*max_element(all(res))+MX*max(0,t-100)<<endl;
}
int main()
{
    cin>>n>>t;a.resize(min(100,t)*n);
    for(int i=0;i<n;i++){cin>>a[i];ocr[a[i]]++;if(ocr[a[i]]>MX)MX=ocr[a[i]];}
    for(int i=n;i<min(t,100)*n;i++)a[i]=a[i%n];
    LIS();
}