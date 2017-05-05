#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
    int a[3][3]; int b[3][3];
    for (int i = 0; i < 3; i++){ for (int j = 0; j < 3; j++){ cin >> a[i][j]; b[i][j] = 1; } }
    bool test = true;
    while (test)
    {
        test = false;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] != 0)
                {
                    a[i][j]--;
                    if (a[i][j] != 0)test = true;
                    if (b[i][j] == 1)b[i][j] = 0; else b[i][j] = 1;
                    if (i == 0)
                    {
                        if (b[i + 1][j] == 1)b[i + 1][j] = 0; else b[i + 1][j] = 1;
                    }
                    else
                    if (i == 2)
                    {
                        if (b[i - 1][j] == 1)b[i - 1][j] = 0; else b[i - 1][j] = 1;
                    }
                    else
                    {
                        if (b[i + 1][j] == 1)b[i + 1][j] = 0; else b[i + 1][j] = 1;
                        if (b[i - 1][j] == 1)b[i - 1][j] = 0; else b[i - 1][j] = 1;
                    }
                    if (j == 0)
                    {
                        if (b[i][j + 1] == 1)b[i][j + 1] = 0; else b[i][j + 1] = 1;
                    }
                    else
                    if (j == 2)
                    {
                        if (b[i][j - 1] == 1)b[i][j - 1] = 0; else b[i][j - 1] = 1;
                    }
                    else
                    {
                        if (b[i][j + 1] == 1)b[i][j + 1] = 0; else b[i][j + 1] = 1;
                        if (b[i][j - 1] == 1)b[i][j - 1] = 0; else b[i][j - 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; i++){ for (int j = 0; j < 3; j++){ cout << b[i][j]; }cout << endl; }
}