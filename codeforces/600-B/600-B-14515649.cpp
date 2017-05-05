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
#define R_W        R_("easy.in"),W_("easy.out")
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
#define pr3(n)     cout<<fixed<<setprecision(9)<<n<<endl
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
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int a[MAX], b[MAX], n, m;
class unionFind
{
    vector<int> rank, parent;
public:
    unionFind(int n)
    {
        rank.resize(n); parent.resize(n);
        for (int i = 0; i < n; ++i)rank[i] = 0, parent[i] = i;
    }
    int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
    bool isSameSet(int i, int j) { return find_set(i) == find_set(j); }
    bool union_set(int i, int j) {
        if (!isSameSet(i, j))
        {
            int x = find_set(i), y = find_set(j); if (rank[x] > rank[y]) parent[y] = x;
            else { parent[x] = y; if (rank[x] == rank[y]) rank[y]++; }
            return 1;
        }
        return 0;
    }
};
int bs(int value)
{
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] <= value)s = mid + 1, ans = mid;
        else e = mid - 1;
    }
    return ans + 1;
}
int main()
{
    cin >> n >> m;
    lop(i, 0, n)cin >> a[i];
    lop(i, 0, m)cin >> b[i];
    sort(a, a + n);
    lop(i, 0, m)cout << bs(b[i]) << " "; cout << endl;
}