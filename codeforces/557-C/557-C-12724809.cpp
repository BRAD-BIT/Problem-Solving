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
//#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
//#include<array>
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
int const MAX = 1e5 + 7;
int const MOD = 1e9 + 7;
struct node{ll len, enrgy, sum, cnt;};
node arr[MAX]; map<int, int>mp; int d[210];
bool comp(node a, node b)
{
    return a.len < b.len;
}
int main()

{
    ll n, ans = oo; scl(n);
    lop(i, 0, n)scl(arr[i].len), mp[arr[i].len]++;
    lop(i, 0, n)scl(arr[i].enrgy);
    sort(arr, arr + n,comp);
    lop(i, 0, n)
    {
        arr[i].sum = arr[i].enrgy; if (i)arr[i].sum += arr[i - 1].sum;
        arr[i].cnt = mp[arr[i].len];
    }
    arr[n].len = -1;
    lop(i, 0, n)
    {
        int a = arr[i].len; int s = i;
        lop(j, i, n+1){  if (a != arr[j].len){ i = j - 1; break; } }
        int size_now = i + 1 - arr[i].cnt;
        if (arr[i].cnt>size_now)ans = min(ans, arr[n - 1].sum - arr[i].sum);
        else
        {
            int v = size_now - (arr[i].cnt - 1), removed = 0;
            lop(k, 1, 201)
            {
                if (d[k] <= v)removed += d[k] * k, v -= d[k];
                else removed += k * v, v = 0;
                if (v == 0)break;
            }
            if (v==0)
            ans = min(ans, arr[n - 1].sum - arr[i].sum+removed);
        }
        lop(u, s, i + 1)d[arr[u].enrgy]++;
    }
    cout << ans << endl;
}