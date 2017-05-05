#include<iostream>
using namespace std;
int main()
{
    long long n, x, y, maxX = -1000000000, maxY = -1000000000, minX = 1000000000, minY = 1000000000; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x > maxX)maxX = x;
        if (x < minX)minX = x;
        if (y > maxY)maxY = y;
        if (y < minY)minY = y;
    }
    x = abs(maxX - minX), y = abs(maxY - minY); x = x*x; y = y*y;
    if (x>y)cout << x << endl; else cout << y << endl;
}