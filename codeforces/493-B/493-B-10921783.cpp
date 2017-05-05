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
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int main()
{
    ll n;cin >> n; ll last, sumA = 0, sumB = 0; vector<ll>A, B;
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        if (x>0){ last = 1; sumA += x; A.push_back(x); }
        else{ last = 2; sumB += (-x); B.push_back(-x); }
    }
    if (sumA > sumB)cout << "first" << endl;
    else
    if (sumA < sumB)cout << "second" << endl;
    else
    {
        for (int i = 0; i < min(A.size(), B.size()); i++)
        {
            if (A[i] != B[i])
            {
                if (A[i]>B[i]){ cout << "first" << endl; return 0; }
                else { cout << "second" << endl; return 0; }
            }
        }
        if (A.size()>B.size()){ cout << "first" << endl; return 0; }
        if (A.size()<B.size()){ cout << "second" << endl; return 0; }
        if (last == 1)cout << "first" << endl; else cout << "second" << endl;
    }
}