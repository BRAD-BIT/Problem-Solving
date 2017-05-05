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
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#include<string>
#include<cstdio>

#define lop(i,n)   for(int i=0;i<n;++i)
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define ld         long double
#define sz(v)      (ll)v.size()
#define ii         pair<ll,ll>
#define vii        vector<ii>
#define vi         vector<int>
#define vll        vector<ll>
#define vs         vector<string>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define vvll       vector<vector<ll>>
#define all(v)     v.begin(),v.end()
#define sc(n)      scanf("%d",&n)
#define scl(n)     scanf("%lld",&n)
#define pr1(n)     printf("%d\n",n)
#define pr2(n)     printf("%d " ,n)
#define pr3(n)     cout<<fixed<<setprecision(10)<<n<<endl
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
using namespace std;
int mod = 1000000007;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
struct matrix
{
    vvll mat; matrix(ll n, ll m, ll num=-1)
    {
        
        mat.resize(n);
        if (num==-1)
        lop(i, n){ mat[i].resize(m, 0); mat[i][i] = 1; }
        else
        lop(i, n)mat[i].resize(m, num);
    }
};
vvll multi_matrix(vvll a, vvll b)
{
    matrix c(a.size(), b[0].size(), 0);
    lop(i, a.size())lop(j, b[0].size())
    {
        lop(k, b.size())c.mat[i][j] += (a[i][k] * b[k][j])%mod;
    }
    return c.mat;
}
vvll matrix_power(vvll a, ll k)
{
    if (k == 0){ matrix c(a.size(), a.size()); return c.mat; }
    if (k % 2 == 1)return multi_matrix(a, matrix_power(a, k - 1));
    return matrix_power(multi_matrix(a, a), k / 2);
}
ll solve(ll n)
{
    if (n == 0)return 1;
    matrix a(2, 2, 0), b(2, 2, 0);
    a.mat[0][1] = b.mat[0][1] = b.mat[1][0] = 1;
    b.mat[0][0] = b.mat[1][1] = 3;
    vvll ans = multi_matrix(a.mat, matrix_power(b.mat, n));
    return ans[0][1]%mod;
}
int main()
{
    ll n; scl(n);
    printf("%lld\n", solve(n));
}