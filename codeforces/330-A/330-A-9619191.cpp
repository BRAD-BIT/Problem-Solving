#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    char**a = new char*[r];
    for (int i = 0; i < r; i++)
    {
        a[i] = new char[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    bool test = true;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == 'S')test = false;
        }
        if (test)
        {
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == '.')
                {
                    sum1++;
                    a[i][j] = 'f';
                }
            }
            sum += sum1;
            sum1 = 0;
        }
        test = true;
    }
    test = true;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (a[j][i] == 'S')test = false;
        }
        if (test)
        {
            for (int j = 0; j < r; j++)
            {
                if (a[j][i] == '.')
                {
                    sum2++;
                    a[j][i] = 'f';
                }
            }
            sum += sum2;
            sum2 = 0;
        }
        test = true;
    }
    cout << sum;
}