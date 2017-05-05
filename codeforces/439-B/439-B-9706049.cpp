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
int main()
{
    long long n, x;
    cin >> n >> x;
    long long *a = new long long [n];
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        sum =sum+ a[i] * x;
        x--;
        if (x < 1)x =1;
    }
    cout << sum;
}