#include<iostream>
#include<string>
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
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)return a.second < b.second;
    else return a.first>b.first;
}
int main()
{
    int n, k; cin >> n >> k; pair<int, int> *a = new pair<int, int>[n];
    for (int i = 0; i < n; i++){ cin >> a[i].first >> a[i].second;}
    sort(a, a + n, comp);
    pair<int, int> d = a[k - 1];int sum = 0;
    for (int i = 0; i < n; i++)if (a[i] == d)sum++; cout << sum << endl;
}