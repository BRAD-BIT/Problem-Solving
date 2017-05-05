#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int c = a*b;
    string s1 = "Akshat";
    string s2 = "Malvika";
    int i = 0;
    while (c != 0)
    {
        a = a - 1;
        b = b - 1;
        c = a*b;
        i++;
    }
    if (i % 2 == 0)cout << "Malvika";
    else cout << "Akshat";
}