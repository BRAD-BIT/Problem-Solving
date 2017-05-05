#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int n4 = 0;
    int n3 = 0;
    int n2 = 0;
    int n1 = 0;
    int *s = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int j = 0; j < n; j++)
    {
        if (s[j] == 4)n4 = n4 + 1;
        if (s[j] == 3)n3 = n3 + 1;
        if (s[j] == 2)n2 = n2 + 1;
        if (s[j] == 1)n1 = n1 + 1;
    }
    int taxi, k1, k2;
    if (n3>=n1)
    {
        k1 = n3 - n1;
        taxi = n4 + n1 + k1 + (n2 / 2) + (n2%2);
    }
    else
    if (n1 > n3)
    {
        k2 = n1 - n3;
        if (n2 % 2 == 0 && n2 != 0 && k2 % 4 == 0)
        {
            taxi = n4 + n3 + (n2 / 2) + (k2 / 4) ;
        }
        else
        if (n2 % 2 == 0 && n2 != 0 && k2 % 4 != 0)
        {
            taxi = n4 + n3 + (n2 / 2) + (k2 / 4) + 1;
        }
        else
        {
            if (k2 % 4 == 3 && n2!=0)
                taxi = n4 + n3 + (n2 / 2) + (k2 / 4) + 2;
            else
            if (k2 % 4 == 3 && n2 == 0)
                taxi = n4 + n3 + (n2 / 2) + (k2 / 4) + 1;
            else
            if (k2 % 4 == 0)
            {
                taxi = n4 + n3 + (n2 / 2) + (k2 / 4)+(n2%2);
            }
            else
                taxi = n4 + n3 + (n2 / 2) + (k2 / 4) + 1;
        }

    }
    cout <<taxi;
    return 0;
}