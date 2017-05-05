#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n + 1];
    int *b = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
}