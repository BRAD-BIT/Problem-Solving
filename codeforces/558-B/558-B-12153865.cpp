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
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
map<int, int>mp1, mp2; int arr[100010]; int a[1000010]; 
int main()
{
    int n; cin >> n; int M = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i]; a[arr[i]]++; M = max(M, a[arr[i]]);
    }
    vi num;
    for (int i = 1; i <= 1000000; i++)
    {
        if (a[i] == M)num.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (mp1[arr[i]] == 0)mp1[arr[i]] = i+1;
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (mp2[arr[i]] == 0)mp2[arr[i]] = i+1;
    }
    ii ans; M = oo;
    for (int i = 0; i < num.size(); i++)
    {
        if (mp2[num[i]] - mp1[num[i]] < M)
        {
            M = mp2[num[i]] - mp1[num[i]];
            ans = make_pair(mp1[num[i]], mp2[num[i]]);
        }
    }
    cout << ans.first << " " << ans.second << endl;
}