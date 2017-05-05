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
struct name
{
    string first;
    string last;
};
int main()
{
    int n; cin >> n; name *a = new name[n]; int *b = new int[n]; name *c = new name[n];
    for (int i = 0; i < n; i++){ cin >> a[i].first >> a[i].last; c[i].first = a[i].first; c[i].last = a[i].last; }for (int i = 0; i < n; i++){ cin >> b[i]; }
    bool test = true;
    for (int i = 0; i < n - 1; i++)
    {
        int x = b[i] - 1; int y = b[i + 1] - 1;;
        if (a[x].first < a[y].first){ a[x].last = a[x].first; a[y].last = a[y].first; }
        else
        if (a[x].first < a[y].last){ a[x].last = a[x].first; a[y].first = a[y].last; }
        else
        if (a[x].last < a[y].first){ a[x].first = a[x].last; a[y].last = a[y].first; }
        else
        if (a[x].last < a[y].last){ a[x].first = a[y].last; a[y].first = a[y].last; }
        else
        {
            test = false;
            break;
        }
    }
    bool test1 = true;
    for (int i = 0; i < n - 1; i++)
    {
        int x = b[i] - 1; int y = b[i + 1] - 1;
        if (c[x].last < c[y].last){ c[x].first = c[y].last; c[y].first = c[y].last; }
        else
        if (c[x].last < c[y].first){ c[x].first = c[x].last; c[y].last = c[y].first; }
        else
        if (c[x].first < c[y].first){ c[x].last = c[x].first; c[y].last = c[y].first; }
        else
        if (c[x].first < c[y].last){ c[x].last = c[x].first; c[y].first = c[y].last; }
        else
        {
            test1 = false;
            break;
        }
    }
    if (test||test1)cout << "YES";
    else
        cout << "NO";
}