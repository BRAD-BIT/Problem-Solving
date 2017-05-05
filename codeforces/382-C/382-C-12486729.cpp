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
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
int arr[MAX]; int n;
bool is()
{
    int a = arr[1] - arr[0];
    lop(i, 1, n)if (arr[i] - arr[i - 1] != a)return 0;
    return 1;
}
int main()
{
    sc(n); lop(i, 0, n)sc(arr[i]); set<int>se; sort(arr, arr + n);
    if (n == 1)return(cout << "-1\n", 0);
    if (n == 2)
    {
        se.insert(2 * arr[0] - arr[1]); if ((arr[0] + arr[1]) % 2 == 0)se.insert((arr[0] + arr[1]) / 2); se.insert(2 * arr[1] - arr[0]);
        cout << se.size() << endl;
        for (set<int>::iterator it = se.begin(); it != se.end(); it++)cout << *it << " "; cout << endl; return 0;
    }
    if (is())
    {
        int a = 2 * arr[0] - arr[1], b = 2 * arr[n - 1] - arr[n - 2]; if (a != b)cout << 2 << "\n" << a << " " << b << endl; else cout << 1 << endl << a << endl; return 0;
    }
    int a = -1, aa = 0, b = -1, bb = 0;
    lop(i, 1, n)
    {se.insert(arr[i] - arr[i - 1]); int dis = arr[i] - arr[i - 1]; if (a == -1)a = dis;else if (b == -1 && a != dis)b = dis;
    if (a == dis)aa++; if (b == dis)bb++;}
    if (aa < bb)a = b, swap(aa, bb);
    if (aa == bb)a = min(a, b);
    if (se.size()>2||a==0||bb>1)return(cout << "0\n", 0);
    lop(i, 1, n)if (arr[i] - arr[i - 1] == a * 2)return(cout << 1 << endl << arr[i] - a << endl, 0);
    cout << "0\n";
}