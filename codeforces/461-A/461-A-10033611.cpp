#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long *a = new long long[n];
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];

    }
    long long sum1 = sum;
    long long sum2 = 0;
    sort(a, a + n);
    for (int i = 0; i < n-1; i++)
    {
        sum2 = sum2 + a[i];
        sum = sum + a[i] +(sum1- sum2);
    }
    cout << sum;

}