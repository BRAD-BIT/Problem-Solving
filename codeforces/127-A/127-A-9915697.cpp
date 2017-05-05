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
struct point{ double x, y; };
int main()
{
    int n, k; cin >> n >> k; point *a = new point[n];
    for (int i = 0; i < n; i++){cin >> a[i].x >> a[i].y;}
    double sum = 0;
    for (int i = 1; i < n; i++){sum += sqrt(pow(a[i].x - a[i-1].x, 2.000) + pow(a[i].y - a[i-1].y, 2.000));}
    double l = (sum / 50)*k; cout << fixed << setprecision(10) << l << endl;
}