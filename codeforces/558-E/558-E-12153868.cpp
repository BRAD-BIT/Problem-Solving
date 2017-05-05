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
#define endl       "\n"
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
int dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 }; 
int to, from, k; string s; vi char_num;
class Segment_Tree
{
public:
    vvi ST; vi sort_type;
    Segment_Tree(int n){ ST.resize(4 * n); sort_type.resize(4 * n, -1); }
    void bulid(int p, int start, int end)
    {
        ST[p].resize(26, 0);
        if (start == end){ ST[p][int(s[start] - 'a')] = 1; return; }
        int mid = (start + end) / 2;
        bulid(2 * p, start, mid);
        bulid(2 * p + 1, mid + 1, end);
        lop(i,26)
            ST[p][i] = ST[2 * p][i] + ST[2 * p + 1][i];
    }
    void lazy(int p, int start, int end)
    {
        int mid = (start + end) / 2;
        if (sort_type[p]!=-1)
        {
            int rem = (mid - start + 1); int t; vi tem = ST[p];
            if (sort_type[p])
            {
                lop(i, 26){ t = min(rem, tem[i]); ST[2 * p][i] = t; rem -= t; }
                lop(i, 26){ ST[2 * p + 1][i] = tem[i] - ST[2 * p][i]; }
            }
            else
            {
                lop(i, 26){ t = min(rem, tem[25-i]); ST[2 * p][25-i] = t; rem -= t; }
                lop(i, 26){ ST[2 * p + 1][i] = tem[i] - ST[2 * p][i]; }
            }
            sort_type[2*p] = sort_type[2*p+1] = sort_type[p];
            sort_type[p] = -1;
        }
    }
    void update1(int p, int start, int end)
    {
        if (start>to || from > end)return;
        if (start >= from&&end <= to)
        {
            lop(i, 26)char_num[i] += ST[p][i]; 
            return;
        }
        lazy(p, start, end);
        int mid = (start + end) / 2;
        update1(2 * p, start, mid);
        update1(2 * p + 1, mid + 1, end);
    }
    void update2(int p, int start, int end)
    {
        if (start>to || from > end)return;
        if (start >= from&&end <= to)
        {
            int rem=(end - start + 1); int t;
            lop(i, 26)
            {
                if (k)t = min(rem, char_num[i]), ST[p][i] = t, char_num[i] -= t;
                else t = min(rem, char_num[25 - i]), ST[p][25 - i] = t, char_num[25 - i] -= t;
                rem -= t;
            }
            sort_type[p] = k;
            return;
        }
        lazy(p, start, end);
        int mid = (start + end) / 2;
        update2(2 * p, start, mid);
        update2(2 * p + 1, mid + 1, end);
        lop(i, 26)ST[p][i] = ST[2*p][i] + ST[2*p+1][i];
    }
    void print(int p, int start, int end)
    {
        if (start==end)
        {
            lop(i, 26)if (ST[p][i])cout << char(i + 'a'); return;
        }
        lazy(p, start, end);
        int mid = (start + end) / 2;
        print(2 * p, start, mid);
        print(2 * p + 1, mid + 1, end);
    }
};
int main()
{
    int n, q; sc(n), sc(q); cin >> s;
    Segment_Tree ST(n);
    ST.bulid(1, 0, n-1);
    lop(i, q)
    {
        sc(from), sc(to), sc(k); from--, to--;
        char_num.resize(26, 0);
        ST.update1(1, 0, n-1);
        ST.update2(1, 0, n-1);
        char_num.clear();
    }
    ST.print(1, 0, n - 1);
    cout << endl;
}