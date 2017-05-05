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
#define ii         pair<int,int>
#define vii        vector<ii>
#define vi         vector<int>
#define vvii       vector<vector<ii>>
#define vvi        vector<vector<int>>
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
#define oo  1e9
using namespace std;
vector<ll> A; ll from = 0, to, height;
class SegmentTree
{
public:
    vector<ll> ST; vi ismixed;
    SegmentTree(int num)
    {
        ST.resize(4 * num, 0);
        ismixed.resize(4 * num, 1);
    }
    ll bulid(int p, int start, int end)
    {
        if (start == end){ ismixed[p] = 0; return ST[p] = A[start]; }
        int mid = (start + end) / 2;
        return ST[p] = max(bulid(2 * p, start, mid), bulid(2 * p + 1, mid + 1, end));
    }
    void lazy_update(int p, int start, int end)
    {
        if (from > end || to <start )return;
        if (start >= from&&to >= end&&!ismixed[p])
        {
            ST[p] = height;
            return;
        }
        int mid = (start + end) / 2;
        if (!ismixed[p])ST[2 * p] = ST[p], ST[2 * p + 1] = ST[p];

        lazy_update(2 * p, start, mid);
        lazy_update(2 * p + 1, mid + 1, end);

        ST[p] = max(ST[2 * p], ST[2 * p + 1]);
        ismixed[p] = ismixed[2 * p] || ismixed[2 * p + 1] || ST[2*p] != ST[2 * p + 1];
    }
    ll get_max(int p, int start, int end)
    {
        if (end < from||to < start)return 0;
        int mid = (start + end) / 2;
        if ((start >= from&&to >= end)||(start <= from&&to <= end)&&!ismixed[p])
        {
            return ST[p];
        }
        ll a = get_max(2 * p, start, mid);
        ll b = get_max(2 * p + 1, mid + 1, end);
        return max(a, b);
    }
};
int main()
{
    //R_W;
    ll n, m, h; cin >> n; A.resize(n);
    for (int i = 0; i < n; ++i)scanf("%d", &A[i]);
    SegmentTree ST(n);
    ST.bulid(1, 0, n - 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> to >> height;
        /*scanf("%d%d", &to, &height);*/ ll h = height; --to; height += ST.get_max(1, 0, n - 1);
        ST.lazy_update(1, 0, n - 1);
        cout << ST.get_max(1, 0, n - 1) - h << endl;
    }
}