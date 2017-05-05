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
int arr[MAX],q[MAX],l,r;ii cur;map<int,int>mp;
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b); }
class Sparse_Table
{
public:
    vvi ST[2];
    Sparse_Table(int N,int MAX_log)
    {
        ST[0].resize(N);ST[1].resize(N);
        lop(i,0,N)ST[0][i].resize(MAX_log),ST[1][i].resize(MAX_log);
        lop(i,0,N)ST[0][i][0]=i,ST[1][i][0]=arr[i];
        for(int j=1;(1<<j)<=N;++j)
            for(int i=0;i+(1<<j)-1<N;++i){
                if(arr[ST[0][i][j-1]]<arr[ST[0][i+(1<<(j-1))][j-1]])ST[0][i][j]=ST[0][i][j-1];
                      else ST[0][i][j]=ST[0][i+(1<<(j-1))][j-1];
                      ST[1][i][j]=gcd(ST[1][i][j-1],ST[1][i+(1<<(j-1))][j-1]);}
    }
    int RMQ()
    { 
        int k = (int)floor(log((double)r-l+1) / log(2.0));
        if (arr[ST[0][l][k]] <= arr[ST[0][r-(1<<k)+1][k]])return arr[ST[0][l][k]];
        else return arr[ST[0][r-(1<<k)+1][k]]; 
    }
    int GCD()
    {
        int k = (int)floor(log((double)r-l+1) / log(2.0));
        return gcd(ST[1][l][k],ST[1][r-(1<<k)+1][k]); 
    }
};
int main() 
{
    int n;sc(n);
    lop(i,0,n)sc(arr[i]);
    Sparse_Table SpT(n,20);
    int s=0,e=n-1,mid,found,x;ii ans(-1,1);
    while(s<=e)
    {
        mid=(s+e)/2;found=0,x=0;
        lop(i,0,n-mid)
        {
            l=i,r=i+mid;
            if(SpT.GCD()==SpT.RMQ()){found=1;x++;}
        }
        if(found)if(mid>ans.first)ans=ii(mid,x);
        if(found)s=mid+1;
        else e=mid-1;
    }
    pr2(ans.second),pr1(ans.first);
    lop(i,0,n-ans.first){l=i,r=i+ans.first;if(SpT.GCD()==SpT.RMQ())pr2(i+1);}
    cout<<endl;
}