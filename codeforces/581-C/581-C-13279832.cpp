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
ii arr[100007];
int nearest(int n)
{
    while((n%10!=0||n==0)&&n<100)n++;
    return n;
}
bool comp(ii a,ii b)
{
    return (nearest(a.first)-a.first)<(nearest(b.first)-b.first);
}
int main()
{
    int n,k;cin>>n>>k;
    int ans=0;
    lop(i,0,n)cin>>arr[i].first;
    sort(arr,arr+n,comp);
    lop(i,0,n)
    {
        if(nearest(arr[i].first)-arr[i].first>0&&nearest(arr[i].first)-arr[i].first<=k)
            k-=(nearest(arr[i].first)-arr[i].first),arr[i].first=nearest(arr[i].first);
    }
    lop(i,0,n)
    {
        while(k>=10&&arr[i].first<100)
        k-=10,arr[i].first+=10;
        ans+=floor(arr[i].first/10.00000);
    }
    cout<<ans<<endl;
}