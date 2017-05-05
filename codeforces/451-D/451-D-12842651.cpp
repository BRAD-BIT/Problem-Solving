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
//#include<regex>
using namespace std;
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
#define pr3(n)     cout<<fixed<<setprecision(3)<<n
#define endl       "\n"
#define PI         3.14159265358979323846
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
#define OO  1e18
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int const MAX = 1e6 + 7;
int const MOD = 1e9 + 7;
int main()
{
    string s;
    while (cin >> s){
        int odd_a = 0, odd_b = 0, even_a = 0, even_b = 0;
        ii ans(0, 0);
        lop(i, 0, s.length())
        {
            if (i % 2 == 0)if (s[i] == 'a')++even_a; else ++even_b;
            else if (s[i] == 'a')++odd_a; else ++odd_b;
            if (s[i] == 'a')
            {
                if (i % 2 == 0)ans.first += odd_a, ans.second += even_a; 
                else ans.first += even_a, ans.second += odd_a;
            }
            else 
            {
                if (i % 2 == 0)ans.first += odd_b, ans.second += even_b;
                else ans.first += even_b, ans.second += odd_b;
            }

        }
        cout << ans.first << " " << ans.second << endl;
    }
}