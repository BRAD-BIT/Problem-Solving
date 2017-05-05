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
vii pos, neg;
bool comp1(ii a, ii b){ return a.first < b.first; }
bool comp2(ii a, ii b){ return a.first > b.first; }
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        if (a < 0)
            neg.push_back(make_pair(a, b));
        else pos.push_back(make_pair(a, b));
    }
    if(neg.size()!=0)sort(all(neg),comp2);
    if(pos.size()!=0)sort(all(pos),comp1);
    int v = 0, u = 0; int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (v < neg.size())
            sum1 += neg[v].second, v++;
            else break;
        }
        else
        {
            if (u < pos.size()) 
                sum1 += pos[u].second, u++; 
            else break;
        }
    }
    v = 0, u = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (v < pos.size())
            sum2 += pos[v].second, v++;
            else break;
        }
        else
        {
            if (u < neg.size())
                sum2 += neg[u].second, u++;
            else break;
        }
    }
    cout << max(sum1, sum2) << endl;
}