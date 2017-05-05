#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a = 0;
    int day = 0;
    while (n != 0)
    {
        if (a != m)
        {
            day = day + 1;
            a++;
            n--;
            if (n == 0 && a==m)
            {
                day = day + 1;
            }
        }
        else
        {
            n++;
            a = 0;
        }
    }
    cout << day;
}