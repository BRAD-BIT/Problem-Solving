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
bool iscoprime(long long  a, long long b)
{
    if (a == 1)return true;
    else
    if (b%a == 0)return false;
    else
    if (a % 2 != 0 && b % 2 != 0)return true;
    else
    if ((a % 2 == 0 && b % 2 != 0) || (b % 2 == 0 && a % 2 != 0))return true;
    else return false;
}
int main()
{
    long long l, r;
    cin >> l >> r;
    long long a, b, c;
    bool test = false;
    for (long long i = l; i <= r - 2; i++)
    {
        for (long long j = i+1; j <= r - 1; j++)
        {
            for (long long k = j+1; k <= r; k++)
            {
                a = i;
                b = j;
                c = k;
                if (iscoprime(a, b) && iscoprime(b, c) && !iscoprime(a, c))
                {
                    test = true;
                    cout << a << " " << b << " " << c << endl;
                    break;
                }
            }
            if (test)break;
        }
        if (test)break;
    }
    if (!test)cout << -1 << endl;
}