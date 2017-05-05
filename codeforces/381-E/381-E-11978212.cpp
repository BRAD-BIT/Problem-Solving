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
struct node{ int open, closed, max_sec; node(int a = 0, int b = 0, int c = 0){ open = a; closed = b; max_sec = c; } };
string A; int from, to;
class SegmentTree
{
public:
    vector<node> ST;
    SegmentTree(int num)
    {
        ST.resize(4 * num);
    }
    node join(node left, node right)
    {
        int mn = min(left.open, right.closed);
        int a = left.open + right.open - mn;
        int b = left.closed + right.closed - mn;
        int c = left.max_sec + right.max_sec + 2 * mn;
        return node(a, b, c);
    }
    void bulid(int p, int start, int end)
    {
        if (start == end)
        {
            ST[p].open = (A[start] == '(');
            ST[p].closed = (A[start] == ')');
            return;
        }
        int mid = (start + end) / 2;
        bulid(2 * p, start, mid); bulid(2 * p+1, mid + 1, end);
        ST[p] = join(ST[2 * p], ST[2 * p + 1]);
    }
    node get(int p, int start, int end)
    {
        if (start>end||end<from||start>to)return node();
        int mid = (start + end) / 2;
        if (from <= start&&to >= end)return ST[p];
        node a = get(2 * p, start, mid);
        node b = get(2 * p+1, mid+1, end);
        return join(a, b);
    }
};
int main()
{
    //R_W;
    cin >> A; int m, a, b;
    SegmentTree ST(A.size());
    ST.bulid(1, 0, A.size() - 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &from, &to); from--, to--;
        printf("%d\n", ST.get(1, 0, A.size() - 1).max_sec);
    }
}