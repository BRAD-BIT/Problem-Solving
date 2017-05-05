#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long sum25 = 0;
    long long sum50 = 0;
    bool test = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 25)sum25++;
        else
        if (a[i] == 50)
        {
            sum50++;
            sum25--;
            if (sum25 < 0)
            {
                test = false;
                break;
            }
        }
        else
        {
            sum25--;
            sum50--;
            if (sum50<0 || sum25<0)
            {
                sum25 -= 2;
                sum50++;
                if (sum25<0)
                {
                    test = false;
                    break;
                }
            }
        }
    }
    if (test)cout << "YES";
    else cout << "NO";
}