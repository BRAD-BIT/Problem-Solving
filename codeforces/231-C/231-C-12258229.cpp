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

#define lop(i,n)   for(ll i=0;i<n;++i)
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
ll mod = 1e9 + 7;
const int MAX = 1e5 + 7;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
struct a{ ll num, oc, sum;};
bool comp(a x, a y){ return x.num < y.num; }
map<int, int>mp; int n, k; a arr[MAX]; vii v; ii cur;
int binary_search()
{
    ll start = 0, end = cur.second - 1, mid, x, y, ans = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        x = (cur.second - mid);
        y = arr[cur.second - 1].sum - arr[mid].sum + arr[mid].num;
        x = x*cur.first;
        x -= y;
        if (x > k)
        {
            start = mid + 1;
        }
        else 
            if (x <= k)
            {
            end = mid - 1;
            ans = mid;
            }
    }
    if (ans != -1)return cur.second - ans;
    return 0;
}
int main()
{
    sc(n), sc(k);
    lop(i, n){ cin >> arr[i].num; mp[arr[i].num]++; arr[i].sum = 0; }
    sort(arr, arr + n,comp);
    lop(i, n){ arr[i].oc = mp[arr[i].num]; arr[i].sum += arr[i].num; if (i)arr[i].sum += arr[i - 1].sum; }
    ii ans(arr[0].oc, arr[0].num); int x = arr[0].num;
    lop(i, n)
    {
        if (arr[i].num != x)
        {
            x = arr[i].num;
            cur = ii(arr[i].num, i);
            int bs = binary_search();
            if (bs + arr[i].oc > ans.first)ans = ii(bs + arr[i].oc, arr[i].num);
        }
    }
    cout << ans.first << " " << ans.second << endl;
}