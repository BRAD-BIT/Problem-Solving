#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int x = s.length();
    string g;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < x; i++)
    {
        if (s[i] == '1')a = a + 1;
        if (s[i] == '2')b = b + 1;
        if (s[i] == '3')c = c + 1;
    }
    int z = a + b + c;
    for (int i = 0; i < a; i++)
    {
        if (i == a - 1 && b == 0 && c == 0)cout << '1';
        else
        cout << "1+";
    }
    for (int i = 0; i < b; i++)
    {
        if (i == b - 1 &&  c == 0)cout << '2';
        else
            cout << "2+";
    }
    for (int i = 0; i < c; i++)
    {
        if (i == c - 1 )cout << '3';
        else
            cout << "3+";
    }
}