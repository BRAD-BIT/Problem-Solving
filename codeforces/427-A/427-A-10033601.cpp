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
    int  *a = new int[n];
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]>0)
        {
            sum=sum+a[i];
        }
        else if (a[i] == -1)
        {
            if (sum != 0)sum--;
            else sum2++;
        }
    }
    cout << sum2;
}