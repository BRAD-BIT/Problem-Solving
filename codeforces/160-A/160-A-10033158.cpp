#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }
    sort(a, a + n);
    int x = (sum / 2);
    int y = 0;
    int sum1 = 0;
    for (int i = n-1; i >=0; i--)
    {
        sum1 = sum1 + a[i];
        if (sum1>x)
        {
            y = y + 1;
            cout << y;
            break;
        }
        else
            y = y + 1;
    }
}