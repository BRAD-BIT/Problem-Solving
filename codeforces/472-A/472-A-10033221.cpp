#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool test1 = false;
    bool test2 = false;
    for (int i = 4; i <= n - i; i++)
    {
        for (int j = 2; j < 10; j++)
        {
            if (i%j == 0 && i / j!=1)
            {
                test1 = true;
                break;
            }
        }
        for (int k = 2; k < 10; k++)
        {
            if ((n-i)%k == 0 && (n-i)/ k!=1)
            {
                test2 = true;
                break;
            }
        }
        if (test1&&test2)
        {
            cout << i << " " << n - i;
            break;
        }
        test1 = false;
        test2 = false;
    }
}