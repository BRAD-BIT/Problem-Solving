#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
struct pile
{
    long long value;
    long begin;
    long end;
};
struct ass
{
    long long value;
    long long pos;
};
bool comp(ass a, ass b)
{
    return a.value < b.value;
}
int main()
{
    long long n;
    cin >> n;
    pile *a = new pile[n];
    int z = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].value;
        a[i].begin = z;
        a[i].end = z + a[i].value - 1;
        z = a[i].end + 1;
    }
    long long m;
    cin >> m;
    ass *b = new ass[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i].value;
        b[i].pos = i;
    }
    ass *c = new ass[m];
    for (int i = 0; i < m; i++)
    {
        long long begin = 0;
        long long end = n - 1;
        long long min = (begin + end) / 2;
        while (b[i].value<a[min].begin||b[i].value>a[min].end)
        {
            if (b[i].value<a[min].begin)
            {
                end = min - 1;
            }
            else
            if (b[i].value>a[min].end)
            {
                begin = min + 1;
            }
            min = (begin + end) / 2;
        }
        cout << min+1 << endl;
    }
}