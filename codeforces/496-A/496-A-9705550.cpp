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
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = 0;
    int max1 = 1010101010101010101;
    int pos;
    for (int i = 1; i < n-1; i++)
    {
        max = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                int z = a[j + 2] - a[j + 1];
                if (z >max&&z >= 0 && z < 1000)
                {
                    pos = i;
                    max = z;
                }
            }
            else
            if (j + 1 == i)
            {
                int z = a[j + 2] - a[j];
                if (z >max&&z >= 0 && z < 1000)
                {
                    pos = i;
                    max = z;
                }
            }
            else
            {
                int z = a[j + 1] - a[j];
                if (z >max&&z >= 0 && z < 1000)
                {
                    pos = i;
                    max = z;
                }
            }
        }
        if (max>max1)max = max1;
        else
        {
            max1 = max;
        }
    }
    cout << max1;
}