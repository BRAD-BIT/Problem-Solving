#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long *a = new long long[n];
    for (int v = 0; v < n; v++)
    {
        cin >> a[v];
    }
    bool test = false;
    bool test1 = false;
    int num = 0;
    int i = 0;
    while (!test1)
    {
        if (num % 2 == 0)
        {
            if (a[i] == 0 && i != n - 1)
            {
                cout << "R";
                i++;
            }
            else
            if (a[i] != 0 && i != n - 1)
            {
                cout << "PR";
                a[i]--;
                i++;
            }
            else
            if (i == n - 1)
            {
                num++;
            }
        }
        else if (num % 2 != 0)
        {
            if (a[i] == 0 && i != 0)
            {
                cout << "L";
                i--;
            }
            else
            if (a[i] - 1 == 0 && i == n - 1)
            {
                cout << "P";
                a[i]--;
            }
            else
            if (a[i] != 0 && i != 0)
            {
                cout << "PL";
                a[i]--;
                i--;
            }
            else
             if (i == 0)num++;
        }
        test1 = true;
        for (int h = 0; h < n; h++)
        {
            if (a[h] != 0)test1 = false;
        }
    }
    cout<<endl;
}