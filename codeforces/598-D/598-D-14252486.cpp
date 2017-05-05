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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n<<endl
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
const int MAX = 1000 + 7;
char grid[MAX][MAX]; int vis[4][MAX][MAX], c_comp[MAX*MAX];
int ID = 1, num, n, m, k;
void DFS(int r, int c)
{
    vis[0][r][c] = ID;
    lop(i, 0, 4)if (r + dr[i] != -1 && r + dr[i] < n&&c + dc[i] != -1 && c + dc[i] < m)
        if (grid[r + dr[i]][c + dc[i]] == '*'&&vis[i][r + dr[i]][c + dc[i]] != ID)
            vis[i][r + dr[i]][c + dc[i]] = ID, c_comp[ID]++;
        else
        if (grid[r + dr[i]][c + dc[i]] == '.'&&vis[0][r + dr[i]][c + dc[i]] != ID)DFS(r + dr[i], c + dc[i]);
}
int main()
{
    cin >> n >> m >> k;
    lop(i, 0, n)lop(j, 0, m)cin >> grid[i][j];
    lop(i, 0, n)lop(j, 0, m)
        if (!vis[0][i][j] && grid[i][j] == '.')DFS(i, j), ID++;

    lop(i, 0, k) { int x, y; cin >> x >> y; cout << c_comp[vis[0][x - 1][y - 1]] << endl; }

}