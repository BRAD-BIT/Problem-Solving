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
struct matrix
{
	vvll mat; matrix(ll n, ll m, ll num = -1)
	{

		mat.resize(n);
		if (num == -1)
			lop(i,0,n){ mat[i].resize(m, 0); mat[i][i] = 1; }
		else
			lop(i,0,n)mat[i].resize(m, num);
	}
};
vvll multi_matrix(vvll a, vvll b)
{
	matrix c(a.size(), b[0].size(), 0);
	lop(i,0, a.size())lop(j,0, b[0].size())
	{
		lop(k,0, b.size())c.mat[i][j] += (a[i][k] * b[k][j]) % MOD;
	}
	return c.mat;
}
vvll matrix_power(vvll a, ll k)
{
	if (k == 0){ matrix c(a.size(), a.size()); return c.mat; }
	if (k % 2 == 1)return multi_matrix(a, matrix_power(a, k - 1));
	return matrix_power(multi_matrix(a, a), k / 2);
}
int main ()
{
	ll n;
	while(cin>>n&&n){
		if(n<4){cout<<n-1<<endl;continue;}
	matrix a(3,3,0);a.mat[0][1]=1,a.mat[0][2]=2;
	matrix b(3,3,1);b.mat[0][0]=b.mat[2][0]=b.mat[0][1]=b.mat[1][1]=0;
	a.mat=multi_matrix(a.mat,matrix_power(b.mat,n-3));
	cout<<a.mat[0][2]%MOD<<endl;
	}
}