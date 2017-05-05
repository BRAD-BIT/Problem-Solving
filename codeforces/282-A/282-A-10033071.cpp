#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = 0;
    string *a = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        if ((a[j][0] == '+' && a[j][1] == '+') || (a[j][0] == '+' && a[j][2] == '+') || (a[j][1] == '+' && a[j][2] == '+'))x = x + 1;
        if ((a[j][0] == '-' && a[j][1] == '-') || (a[j][0] == '-' && a[j][2] == '-') || (a[j][1] == '-' && a[j][2] == '-'))x = x - 1;
    }
    cout << x;
}