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
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
struct ssa{ ll sum, index; };
struct ssa2{ ll sum, a, b; };
bool comp2(ssa2 a, ssa2 b)
{
    if (a.sum != b.sum)return a.sum > b.sum;
    if (a.a != b.a)return a.a < b.a;
    return a.b < b.b;
}
int main()
{
    ll n, k, Sum = 0; cin >> n >> k; ll a[1000001]; ll sum[1000001];
    for (int i = 0; i < n; i++){ cin >> a[i]; Sum += a[i]; sum[i] = Sum; }
    vector<ssa>v1; vector<ssa>v2; vector<ssa2>v3;
    for (int i = 0; i < n; i++)
    {
        if (i + k - 1  < n)
        {
            ssa d; d.index = i + 1;
            if (i != 0)d.sum = sum[i + k - 1] - sum[i - 1]; else d.sum = sum[i + k - 1];
            if (i + 1 <= n - k + 1)v1.push_back(d);
        }
    }
    ssa max; max.sum = 0;
    for (int i = v1.size() - 1; i >= 0; i--)
    {
        if (v1[i].sum >= max.sum){
            max.sum = v1[i].sum; max.index = i + 1;
        }
        v2.push_back(max);
    }
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++)
    {
        if (i + k>v1.size() - 1)break;
        ssa2 d;
        d.sum = v1[i].sum + v2[i + k].sum; d.a = v1[i].index; d.b = v2[i + k].index;
        if (d.b - d.a >= k)v3.push_back(d);
    }
    sort(v3.begin(), v3.end(), comp2);
    cout << v3[0].a << " " << v3[0].b << endl;
}