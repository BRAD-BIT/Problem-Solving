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
const int MAXN = 100000+7;
const int MAXK = 12;
ll cumBIT[MAXK][MAXN + 10];
ll howMany[MAXK][MAXN + 10]; ll dp[MAXN][MAXK];
vi values;map<int, int> mapIndex;
void update(int idx, int k, int n, ll val)
{
    while (idx<n) {
        cumBIT[k][idx] += val;
        idx += (idx&-idx);
    }
}

ll getValue(int idx, int k)
{
    ll ret = 0;
    while (idx>0) {
        ret += cumBIT[k][idx];
        idx -= (idx& (-idx));
    }
    return ret;
}

ll dp_result(vi values, int maxk)
{
    dp[0][1] = 1;
    ll ret = 0;
    lop(i, 1, values.size()) {
        dp[i][1] = 1;
        lop(k, 2, maxk + 1) {
            lop(j, 0, i) {
                if (values[j]<values[i]) {
                    dp[i][k] += dp[j][k - 1];
                }
            }
        }
        ret += dp[i][maxk];
    }
    return ret;
}
int main()
{
    memset(cumBIT, 0, sizeof(cumBIT));
    int n, k; cin >> n >> k; k++;values = vi(n, 0);
    lop(i,0,n) cin >> values[i];
    vi temp = values;
    sort(values.begin(), values.end());
    mapIndex[values[0]] = 1;
    lop(i, 1, n) if (values[i] != values[i - 1]) mapIndex[values[i]] = i + 1;
    values = temp;
    ll ret = 0;
    lop(i,0,n) {
        int index = mapIndex[values[i]];
        howMany[1][i] = 1;
        update(index, 1, n, howMany[1][i]);
        lop(j, 2, k + 1) {
            howMany[j][i] = getValue(index - 1, j - 1);
            update(index, j, n, howMany[j][i]);
        }
        ret += howMany[k][i];
    }
    cout << ret << endl;
}