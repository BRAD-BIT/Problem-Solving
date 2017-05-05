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
vi A;
class SegmentTree
{
public:
    vi ST; int n; int num_level;
    SegmentTree(int num,int num_l)
    {
        num_level = num_l;
        ST.resize(4 * num, 0);
    }
    int bulid(int p, int start, int end,int level)
    {
        if (start == end)return ST[p] = A[start];
        int mid = (start + end) / 2;
        if((num_level-level)%2==0)return ST[p] = bulid(2*p, start, mid,level+1) ^ bulid(2 * p + 1, mid + 1, end,level+1);
        else return ST[p] = bulid(2 * p, start, mid, level + 1) | bulid(2 * p + 1, mid + 1, end, level + 1);
    }
    int change(int p, int start, int end, int level,int kth)
    {
        if (start == end)return ST[p] = A[start];
        int mid = (start + end) / 2;

        if ((num_level - level) % 2 != 0)
        {
            if (kth <= mid)return ST[p] = change(2 * p, start, mid, level + 1, kth) | ST[2 * p + 1];
            else return ST[p] = change(2 * p + 1, mid + 1, end, level + 1, kth) | ST[2 * p];
        }
        else
        {
            if (kth <= mid)return ST[p] = change(2 * p, start, mid, level + 1, kth) ^ ST[2 * p + 1];
            else return ST[p] = change(2 * p + 1, mid + 1, end, level + 1, kth) ^ ST[2 * p];
        }
    }
    
};
int main()
{
    int n, m; cin >> n >> m; int size = pow(2.000, n);
    A.resize(size);
    for (int i = 0; i < size; i++)scanf("%d", &A[i]);
    SegmentTree ST(4 * size, n);
    ST.bulid(1, 0, size - 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; --a;
        A[a] = b;
        ST.change(1, 0, size - 1, 0, a);
        printf("%d\n", ST.ST[1]);
    }
}