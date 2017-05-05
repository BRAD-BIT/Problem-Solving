#include<iostream>
using namespace std;
int main()
{
    int m, k;
    cin >> m >> k;
    int *a = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    if (a[k - 1] == 0)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] > a[k - 1])sum++;
        }
        cout << sum;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] >= a[k - 1])sum++;
        }
        cout << sum;
    }
}