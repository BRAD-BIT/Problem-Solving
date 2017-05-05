#include<iostream>
#include<string>
using namespace std;
int main()
{
    int b;
    string a;
    cin >> a;
    b = a.length();
    char f;
    for (int i = 0; i < b; i++)
    {
        if (a[i] != 'a' && a[i] != 'o' && a[i] != 'y' && a[i] != 'u' && a[i] != 'i' && a[i] != 'e' && a[i] != 'A' && a[i] != 'O' && a[i] != 'Y' && a[i] != 'U' && a[i] != 'I' && a[i] != 'E')
        {
            if (isupper(a[i]))
            {
                f = tolower(a[i]);
                cout << '.' << f;
            }
            else
                cout << '.' << a[i];
        }
        
    }
}