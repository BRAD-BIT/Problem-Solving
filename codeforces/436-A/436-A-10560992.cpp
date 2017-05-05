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
struct candies{ int mass, height, type; };
bool comp(candies a, candies b)
{
    return a.mass > b.mass;
}
int main()
{
    ll n, x, z; cin >> n >> x; vector<candies>a; vector<candies>b; z = x;
    for (int i = 0; i < n; i++)
    {
        candies d; cin >> d.type >> d.height >> d.mass;
        a.push_back(d);
        b.push_back(d);
    }
    sort(a.begin(), a.end(), comp);
    sort(b.begin(), b.end(), comp);
    int max1 = 0,max2=0, T = 0; bool test;
    while (a.size())
    {
        test = false;
        for (int j = 0; j < a.size(); j++)
        {
            if (x >= a[j].height&&a[j].type == T){ max1++; x += a[j].mass; a.erase(a.begin() + j); test = true; break; }
        }
        if (!test)break;
        if (T == 0)T = 1; else T = 0;
    }
    T = 1;
    x = z;
    while (b.size())
    {
        test = false;
        for (int j = 0; j < b.size(); j++)
        {
            if (x >= b[j].height&&b[j].type == T){ max2++; x += b[j].mass; b.erase(b.begin() + j); test = true; break; }
        }
        if (!test)break;
        if (T == 0)T = 1; else T = 0;
    }
    cout << max(max1,max2) << endl;
}