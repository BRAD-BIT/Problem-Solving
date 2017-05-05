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
#define pr3(n)     cout<<fixed<<setprecision(5)<<n
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
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
ll s[MAX][MAX];
ll mem[MAX][MAX];
int N,M;
ll dp(int r,int c)
{
	if(r==0&&c==0)return s[r][c];
	if(mem[r][c]!=-OO)return mem[r][c];
	ll ans1=-oo,ans2=-oo;
	if(c-1>=0)ans1=dp(r,c-1)+s[r][c];
	if(r-1>=0)ans2=dp(r-1,c)+s[r][c];
	mem[r][c]=max(ans1,ans2);
	if(mem[r][c]<=0)mem[r][c]=-(1000)*(500*500);
	return mem[r][c];
}
int is_comp[1000000+7];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		cin>>N>>M;
		lop(i,0,N)lop(j,0,M){cin>>s[i][j];mem[i][j]=-OO;}
		//cout<<dp(N-1,M-1)<<endl;
		int S=1,e=1e9,mid,ans;
		while(S<=e)
		{
			mid=(S+e)/2;
			lop(i,0,N)lop(j,0,M)mem[i][j]=-OO;
			s[0][0]=mid;
			if(dp(N-1,M-1)>=0)e=mid-1,ans=mid;
			else S=mid+1;
		}
		cout<<ans<<endl;
	}
}