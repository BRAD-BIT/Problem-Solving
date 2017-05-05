#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a[3];
    int b[3];
    int m;
    int Suma = 0;
    int Sumb = 0;
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2] >> m;
    int suma = a[0] + a[1] + a[2];
    int sumb = b[0] + b[1] + b[2];
    if (suma%5!=0) Suma = suma / 5 + 1;
    else           Suma = suma / 5;
    if (sumb % 10 != 0) Sumb = sumb / 10 + 1;
    else               Sumb = sumb / 10;
    if (Suma + Sumb > m)cout << "NO";
    else cout << "YES";
}