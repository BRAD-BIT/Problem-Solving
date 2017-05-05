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
int main()
{
    ii arr[6];
    lop(i,0,3)cin>>arr[i].first>>arr[i].second;
    lop(i,0,3){arr[i+3].first=arr[i].second;arr[i+3].second=arr[i].first;}
    lop(i,0,6)
        lop(j,0,6)
           lop(k,0,6)
              if(i!=j&&j!=k&&i!=k)
              {
                  if(arr[j].first==arr[i].first)
                  {
                      if(arr[k].first==arr[i].first&&arr[i].first==arr[i].second+arr[j].second+arr[k].second)
                      {
                          cout<<arr[i].first<<endl;
                          lop(y,0,arr[i].second){lop(x,0,arr[i].first)cout<<char('A'+(i%3));cout<<endl;}
                           lop(y,0,arr[j].second){lop(x,0,arr[j].first)cout<<char('A'+(j%3));cout<<endl;}
                            lop(y,0,arr[k].second){lop(x,0,arr[k].first)cout<<char('A'+(k%3));cout<<endl;}
                            return 0;
                      }
                  }
                  else
                  if(arr[i].second==arr[j].second)
                  {
                      if(arr[k].first==arr[i].first+arr[j].first&&arr[i].first+arr[j].first==arr[k].second+arr[i].second)
                      {
                          cout<<arr[i].first+arr[j].first<<endl;
                          lop(y,0,arr[i].second){lop(x,0,arr[i].first)cout<<char('A'+(i%3));lop(x,0,arr[j].first)cout<<char('A'+(j%3));cout<<endl;}
                          lop(y,0,arr[k].second){lop(x,0,arr[k].first)cout<<char('A'+(k%3));cout<<endl;}
                          return 0;
                      }
                  }
              }
              cout<<"-1\n";
}