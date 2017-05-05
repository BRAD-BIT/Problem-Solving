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
int const MAX = 500 + 7;
int const MOD = 1e9 + 7;
int n;
struct matrix
{
    vvll mat; matrix(ll n, ll m, ll num = -1){
        mat.resize(n);
        if (num == -1)lop(i,0,n){ mat[i].resize(m, 0); mat[i][i] = 1; }
        else lop(i,0,n)mat[i].resize(m, num);
    }
};
vvll multi_matrix(vvll a, vvll b)
{
    matrix c(a.size(), b[0].size(), 0);
    lop(i,0,a.size())lop(j,0,b[0].size())
    {
        lop(k,0,b.size())c.mat[i][j] +=
        (a[i][k] * b[k][j]),c.mat[i][j]=((--c.mat[i][j]+n)%n)+1;
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
    ll sx,sy,dx,dy,t;
    cin>>n>>sx>>sy>>dx>>dy>>t;
    matrix ini(6,6,0);
    ini.mat[0][0]=sx,ini.mat[0][1]=sy,ini.mat[0][2]=dx,ini.mat[0][3]=dy,ini.mat[0][4]=0,ini.mat[0][5]=1;
    matrix ini2(6,6,0);
    ini2.mat[0][0]=2,ini2.mat[0][1]=1,ini2.mat[0][2]=1,ini2.mat[0][3]=1,ini2.mat[0][4]=0,ini2.mat[0][5]=0;
    ini2.mat[1][0]=1,ini2.mat[1][1]=2,ini2.mat[1][2]=1,ini2.mat[1][3]=1,ini2.mat[1][4]=0,ini2.mat[1][5]=0;
    ini2.mat[2][0]=1,ini2.mat[2][1]=0,ini2.mat[2][2]=1,ini2.mat[2][3]=0,ini2.mat[2][4]=0,ini2.mat[2][5]=0;
    ini2.mat[3][0]=0,ini2.mat[3][1]=1,ini2.mat[3][2]=0,ini2.mat[3][3]=1,ini2.mat[3][4]=0,ini2.mat[3][5]=0;
    ini2.mat[4][0]=1,ini2.mat[4][1]=1,ini2.mat[4][2]=1,ini2.mat[4][3]=1,ini2.mat[4][4]=1,ini2.mat[4][5]=0;
    ini2.mat[5][0]=0,ini2.mat[5][1]=0,ini2.mat[5][2]=0,ini2.mat[5][3]=0,ini2.mat[5][4]=1,ini2.mat[5][5]=1;
    ini.mat=multi_matrix(ini.mat,matrix_power(ini2.mat,t));
    cout<<(ini.mat[0][0])<<" "<<ini.mat[0][1]<<endl;
}