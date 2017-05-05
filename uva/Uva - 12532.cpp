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
#define ii         pair<ld,ld>
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
int const MAX = 2*1e6 + 7;
int const MOD = 1e9 + 7;
int arr[MAX],l,r;
class Segment_Tree
{
public:
	vi ST;
	Segment_Tree(int n){ST.resize(4*n);bulid(1,0,n-1);}
	int bulid(int p,int s,int e)
	{
		if(s==e)return ST[p]=arr[s];
		int mid=(s+e)/2;
		return ST[p]=bulid(2*p,s,mid)*bulid(2*p+1,mid+1,e);
	}
	int change(int p,int s,int e,int i)
	{
		if(s==e)return ST[p]=arr[i];
		int mid=(s+e)/2;
		if(i<=mid)change(2*p,s,mid,i);
		else
		change(2*p+1,mid+1,e,i);
		return ST[p]=ST[2*p]*ST[2*p+1];
	}
	int value(int p,int s,int e)
	{
		if(r<s||l>e)return 1;
		if(l<=s&&r>=e)return ST[p];
		int mid=(s+e)/2;
		return value(2*p,s,mid)*value(2*p+1,mid+1,e);
	}
};
int main() 
{
	int n,q;
	while(cin>>n>>q)
	{
		lop(i,0,n){cin>>arr[i];if(arr[i]!=0)arr[i]/=abs(arr[i]);}
		Segment_Tree ST(n);
		lop(i,0,q)
		{
			char o;cin>>o>>l>>r;int v=r;
			if(v!=0)v/=abs(v);
			if(o=='C')arr[--l]=v,ST.change(1,0,n-1,l);
			else
			{
				l--,r--;
				int ans=ST.value(1,0,n-1);
				if(ans>0)cout<<'+';
				else if(ans<0)cout<<'-';else cout<<'0';
			}
		}
		cout<<endl;
	}
}