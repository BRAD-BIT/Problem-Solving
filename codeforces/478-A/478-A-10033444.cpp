#include<iostream>
using namespace std;
int main()
{
    int c1, c2, c3, c4, c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    int c6 = c1 + c2 + c3 + c4 + c5;
    if (c6 % 5 == 0&&c6/5!=0)cout << c6 / 5;
    else cout << -1;
}