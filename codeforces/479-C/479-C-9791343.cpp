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
struct date
{
    long long a;
    long long b;
};
bool comp(date a, date b)
{
    return a.a < b.a;
}
bool comp2(date a, date b)
{
    return a.b < b.b;
}
int main()
{
    int n; cin >> n; date *a = new date[n];for (int i = 0; i < n; i++){ cin >> a[i].a >> a[i].b;} sort(a, a + n, comp);
    long long last = 0;
    for (int i = 0; i < n; i++)
    {
            if (a[i].a != a[i + 1].a || a[i].a == a[i - 1].a)
            {
                if (last <= a[i].b)last = a[i].b;
                else last = a[i].a;
            }
            else
            {
                int x = i;
                int y = i;
                for (int z = x; z < n; z++)
                {
                    if (a[z].a != a[z + 1].a){ y = z; break; }
                }
                sort(a + x, a + y + 1, comp2);
                if (last <= a[i].b)last = a[i].b;
                else last = a[i].a;
            }
    }
    cout << last << endl;
}