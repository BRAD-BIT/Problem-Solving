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
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int main()
{
    int n, k; cin >> n >> k; vi arr(n); map<int, int>mp; set<int>se;ii ans(1, n);
    lop(i, n)
    {
        sc(arr[i]); se.insert(arr[i]); mp[arr[i]]++;
    }
    if (se.size() < k)return(cout << "-1 -1\n",0);
    int i = 0, j = n-1; int num = se.size();
    while (num>k)
    {
        if (mp[arr[i]] > mp[arr[j]]){ mp[arr[i]]--; if (mp[arr[i]] == 0)num--; i++; }
        else
        {
            mp[arr[j]]--; if (mp[arr[j]] == 0)num--; j--;
        }
        ans=ii(i+1, j+1);
    }
    while (1)
    {
        if (mp[arr[i]]>1){ mp[arr[i]]--;i++; }
        if (mp[arr[j]]>1){ mp[arr[j]]--; j--; }
        ans = ii(i + 1, j + 1);
        if (!(mp[arr[i]]>1 || mp[arr[j]]>1))break;
    }
    cout << ans.first << " " << ans.second << endl;
}