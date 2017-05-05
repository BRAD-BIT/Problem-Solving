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
using namespace std;
struct point
{
    int x;
    int y;
};
int main()
{
    int n, sum=0; cin >> n; point *a = new point[n]; for (int i = 0; i < n; i++){ cin >> a[i].x >> a[i].y; }
    for (int i = 0; i < n; i++)
    {
        bool test1 = false;
        bool test2 = false;
        bool test3 = false;
        bool test4 = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i].x == a[j].x&&a[i].y>a[j].y){ test1 = true; }
            if (a[i].x == a[j].x&&a[i].y<a[j].y){ test2 = true; }
            if (a[i].y == a[j].y&&a[i].x>a[j].x){ test3 = true; }
            if (a[i].y == a[j].y&&a[i].x<a[j].x){ test4 = true; }
        }
        if (test1&&test2&&test3&&test4)sum++;
    }
    cout << sum;
}