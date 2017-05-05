#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    char a[1000];
    char ab;
    int index;
    int j = 0;
    for (int i = 0; i < 1000; i++)
    {
        cin >> ab;
        if (ab == '}')break;
        if (ab != ',' && ab != '{' && ab != ' ')
        {
            a[j] = ab;
            j++;
        }
    }
    sort(a, a + j);
    char d = a[0];
    int sum = 1;
    for (int i = 0; i < j; i++)
    {
        if (a[i] != d)
        {
            d = a[i];
            sum++;
        }
    }
    if (j == 0)cout << 0;
    else
    cout << sum;

}