#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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
#define lop(i,a,n) for(ll i=a;i<n;++i)
#define loop(i,n,a)for(ll i=n-1;i>=a;--i)
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
#define pr4(n)     printf("%lld\n",n)
#define pr3(n)     cout<<fixed<<setprecision(2)<<n<<endl
#define endl       "\n"
#define PI         2*acos(0.0)
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
#define EPS pow(10,-9)
int dr[] = { 1, 0, -1, 0, -1, -1, 1, 1 };
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
const int MAX = 1e6 + 7;
const int MOD = 10007;
class Fenwick_Tree
{
public:
    vi FT;
    Fenwick_Tree(int n)
    {
        FT.resize(n + 1, 0);
    }
    int LSOne(int x)
    {
        return x&-x;
    }
    int RSQ(int b)
    {
        if (b <= 0)return 0;
        return FT[b] + RSQ(b - LSOne(b));
    }
    int RSQ(int a, int b)
    {
        return RSQ(b) - RSQ(a - 1);
    }
    void update(int i, int v)
    {
        if (i >= sz(FT))return;
        FT[i] += v; update(i + LSOne(i), v);
    }
};
struct node
{
    int idx, x; node(int X, int I) :x(X), idx(I) {};
};
int arr[MAX];
int last_pos[MAX] = { -1 };
vector<vector<node>> q;
vii ans;
int main()
{
    Fenwick_Tree FT(MAX);
    q.resize(MAX);
    memset(last_pos, -1, sizeof last_pos);
    int n, m; cin >> n;
    lop(i, 0, n)sc(arr[i]);
    sc(m); 
    lop(i, 0, m)
    {
        int x, y; sc(x),sc(y);
        x--, y--;
        q[y].push_back(node(x,i));
    }
    lop(i, 0, n)
    {
        if (last_pos[arr[i]] != -1)
        {
            FT.update(last_pos[arr[i]]+1, -1);
        }
        last_pos[arr[i]] = i;
        FT.update(i+1, 1);
        lop(j, 0, sz(q[i]))
        {
            //cout << "=" << q[i][j] << " " << i << "=\n";
            ans.push_back(ii(q[i][j].idx,FT.RSQ(MAX) - FT.RSQ(q[i][j].x)));
        }
    }
    sort(all(ans));
    lop(i, 0, sz(ans))cout << ans[i].second << endl;
}