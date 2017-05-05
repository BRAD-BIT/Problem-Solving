#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    string b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
    {
        if (isupper(a[i]))
        {
            char x = tolower(a[i]);
            a[i] = x;
        }
        if (isupper(b[i]))
        {
            char y = tolower(b[i]);
            b[i] = y;
        }
    }
    if (a < b)cout << "-1";
    if (a == b)cout << '0';
    if (a > b)cout << '1';
}