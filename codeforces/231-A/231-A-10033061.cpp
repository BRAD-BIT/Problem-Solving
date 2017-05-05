#include<iostream>
using namespace std;
int main()
{
    int n;
    int x;
    int y;
    int z;
    int sum;
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >>y >>z;
        if ((x == 1 && y == 1) || (x == 1 && z == 1) || (y == 1 && z == 1))
            sum = sum + 1;
    }
    cout << sum;
}