#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int x = n.length();
    int y = 0;
    for (int i = 0; i < x; i++)
    {
        if (n[i] == '4' || n[i] == '7')y = y + 1;
    }
    if (y == 4 || y==7)cout << "YES";
    else
        cout << "NO";
}