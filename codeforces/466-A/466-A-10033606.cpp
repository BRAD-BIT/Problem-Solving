#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>  
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (m <= n)
    {
        if (m*a > b)
        {
            if (a < b)
            {
                cout << b*(n / m) + (n%m)*a;
            }
            else
            {
                if (n%m != 0)
                {
                    cout << b*(n / m) + b;
                }
                else cout << b*(n / m) ;
            }
        }
        else cout << a*n;
    }
    else
    {
        if ((n%m)*a < b)
        {
            cout << (n%m)*a;
        }
        else cout <<b;
    }
}