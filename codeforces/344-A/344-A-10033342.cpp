#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 1;
    for (int i = 0; i < n - 1;i++)
    {
        if (a[i] != a[i + 1])
        {
            sum++;
        }
    }
    cout << sum;
    
}