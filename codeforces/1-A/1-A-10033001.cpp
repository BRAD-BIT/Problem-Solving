#include<iostream>;
using namespace std;
int main()
{
    int n, m, a;
    long long x, y;
    long long z;
    cin >> n >> m >> a;
    x = n / a;
    if (n%a!=0) x = x + 1;
    y = m / a;
    if (m%a !=0) y = y + 1;
    z = x*y;
    cout << z;
    return 0;
}