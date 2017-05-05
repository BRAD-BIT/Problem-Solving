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
#define pr3(n)     cout<<fixed<<setprecision(6)<<n<<endl
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
vi is_prime; int arr[MAX], sum[10000000 + 7], prime_factors[10000000 + 7], ocr[10000000 + 7];
void Prime_Sieve(ll n)
{
    is_prime.resize(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= 10000000; i++)
        if (is_prime[i])
        for (int j = 2 * i; j <= n; j += i)
            is_prime[j] = 0, prime_factors[i] += ocr[j]; 
    lop(i, 2, n + 1)
        if (is_prime[i])prime_factors[i] += ocr[i];
}
int main()
{
    //R_("input.txt");
    int n; sc(n);
    lop(i, 0, n){ sc(arr[i]); ocr[arr[i]]++; }  
    Prime_Sieve(10000000);
    sort(arr, arr + n);
    lop(i, 2, 10000001)
    {
        sum[i] = prime_factors[i] + sum[i - 1];
    }
    int q; sc(q);
    lop(i, 0, q)
    {
        int l, r; cin >> l >> r; r = min(r, 10000000); l = min(l, 10000000);
        pr1(sum[r] - sum[l] + prime_factors[l]);
    }
}