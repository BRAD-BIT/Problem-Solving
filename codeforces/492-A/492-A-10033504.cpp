#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    long long a;
    cin >> a;
    long long sum = 0;
    long long i = 0;
    while (a>0)
    {
        i++;
        sum = sum + i;
        a = a - sum;
        if (a < 0)
        {
            i--;
        }
    }
    cout << i;

}