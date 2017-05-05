#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i1, j1, k;
    int sumi = 0;
    int sumj = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> k;
            if (k == 1)
            {
                i1 = i;
                j1 = j;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (i1 == 2 && j1 == 2)break;
        if (i1>2)
        {
            i1--;
            sumi++;
        }
        else
        if (i1<2)
        {
            i1++;
            sumi++;
        }
        if (j1>2)
        {
            j1--;
            sumj++;
        }
        else
        if (j1<2)
        {
            j1++;
            sumj++;
        }
    }
    cout << sumi + sumj;
}