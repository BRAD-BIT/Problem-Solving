#include<iostream>
using namespace std;
int main()
{
    int n, q, p;
    cin >> n;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> q >> p;
        if ((p - q) >= 2)sum++;
    }
    cout << sum;
    return 0;
}