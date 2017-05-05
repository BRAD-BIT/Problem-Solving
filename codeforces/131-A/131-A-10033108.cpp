#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int n1 = 0;
    int n2 = 0;
    if (isupper(a[0]) && a.length() != 1)
    {
        for (int i = 1; i < a.length(); i++)
        {
            if (isupper(a[i]))n1 = 1;
            else
            {
                n1 = 0;
                break;
            }
        }
        if (n1 == 1)
        {
            for (int i = 0; i < a.length(); i++)
            {
                char x = tolower(a[i]);
                a[i] = x;
            }
        }
    }
    if (islower(a[0]) && a.length() != 1)
    {
        for (int i = 1; i < a.length(); i++)
        {
            if (isupper(a[i]))n2 = 1;
            else
            {
                n2 = 0;
                break;
            }
        }
        if (n2 == 1)
        {
            char y = toupper(a[0]);
            a[0] = y;
            for (int i = 1; i < a.length(); i++)
            {
                char x = tolower(a[i]);
                a[i] = x;
            }
        }
    }
    if (a.length() == 1)
    {
        if (islower(a[0]))
        {
            char x = toupper(a[0]);
            a[0] = x;
        }
        else
        {
            char y = tolower(a[0]);
            a[0] = y;
        }
    }
    cout << a;
}