#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <iterator>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int a, b, c; int mo[4001];
int cuts(int n)
{
    if (n == 0)return 0;
    if (n < 0)return -10000000;
    if (mo[n] != -1)return mo[n];
    mo[n] = max(cuts(n - a) + 1, max(cuts(n - b) + 1, cuts(n - c) + 1));
    return mo[n];
}
int main()
{
    int l; cin >> l >> a >> b >> c; for (int i = 0; i < 4001; i++)mo[i] = -1;
    cout << cuts(l) << endl;
}