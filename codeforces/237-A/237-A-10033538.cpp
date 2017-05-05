#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
struct time
{
    int h;
    int m;
};
int main()
{
    int n;
    cin >> n;
    time *a = new time[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].h >> a[i].m;
    }
    int max1 = 0;
    int max2 = 0;
    stack<time>k;
    bool test;
    for (int i = 1; i < n; i++)
    {
        k.push(a[i-1]);
        if (k.top().h == a[i].h&&k.top().m == a[i].m)
        {
            max1++;
        }
        else
        {
            if (max1>max2)max2 = max1;
            max1 = 0;
        }
    }
    if (max1>max2)max2 = max1;
    cout << max2+1;
}