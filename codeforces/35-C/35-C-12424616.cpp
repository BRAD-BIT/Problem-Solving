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
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
const int MAX = 2000 + 7; int dis[MAX][MAX];
int n, m;
void BFS()
{
    int k; cin >> n >> m >> k;
    queue<ii>q; memset(dis, -1, sizeof dis);
    lop(i, 0, k)
    {
        int a, b; cin >> a >> b; --a, --b; dis[a][b] = 1; q.push(ii(a, b));
    }
    ii cur;int dep;
    while (!q.empty())
    {
        cur = q.front(); q.pop(); dep = dis[cur.first][cur.second];
        lop(i, 0, 4)
        {
            ii child = ii(cur.first+dr[i],cur.second+dc[i]);
            if (child.first < 0 || child.first >= n || child.second < 0 || child.second >= m)continue;
            if (dis[child.first][child.second] == -1){ dis[child.first][child.second] = dep + 1; q.push(child); }
        }
    }
    pair<int, ii>ans;
    lop(i, 0, n)
        lop(j, 0, m)
        if (dis[i][j] > ans.first)ans.first = dis[i][j], ans.second = ii(i+1,j+1);
    cout << ans.second.first << " " << ans.second.second << endl;
}
int main()
{
    R_W;
    BFS();
}