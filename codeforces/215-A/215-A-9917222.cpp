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
int main()
{
    int n; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i];
    int m; cin >> m; int *b = new int[m]; for (int i = 0; i < m; i++)cin >> b[i];
    vector<int> v;
    for (int i = 0; i < m; i++)
    {for (int j = 0; j < n; j++){if (b[i] % a[j] == 0)v.push_back(b[i] / a[j]);}}
    sort(v.begin(), v.end()); int max = v[v.size() - 1], sum = 0;
    for (int i = 0; i < v.size(); i++)if (v[i] == max)sum++;
    cout << sum << endl;
}