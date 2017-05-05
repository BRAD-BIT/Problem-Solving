#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <stdio.h>
#include<fstream>
using namespace std;
struct point
{
    double x, y;
    double slope;
};
int main()
{
    int n;double x, y,zum=0; cin >> n >> x >> y; point *a = new point[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        if (a[i].x == x)zum++;
        else
        a[i].slope = (y - a[i].y) / (x - a[i].x);
    }
    set<double> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i].x != x)s.insert(a[i].slope);
    }
    double po;
    if (zum != 0)po = s.size() + 1;
    else po = s.size();
    cout << po << endl;
}