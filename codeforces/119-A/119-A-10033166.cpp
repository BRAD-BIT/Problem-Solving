#include<iostream>
using namespace std;
int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    bool test = true;
    int maxA = 0;
    int maxB = 0;
    while (true)
    {
        for (int i = a; i >= 1; i--)
        {
            if (n%i == 0 && a%i == 0)
            {
                maxA = i;
                break;
            }
        }
        if (n - maxA >= 0)
        {
            n = n - maxA;
        }
        else
        {
            cout << 1;
            break;
        }
        for (int j = b; j >= 1; j--)
        {
            if (n%j == 0 && b%j == 0)
            {
                maxB = j;
                break;
            }
        }
        if (n - maxB >= 0)
        {
            n = n - maxB;
        }
        else
        {
            cout << 0;
            break;
        }
    }
}