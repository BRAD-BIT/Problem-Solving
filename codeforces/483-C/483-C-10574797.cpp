#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <iterator>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int a = 0, b = n + 1;
        for (int i = 0; i < k - 1; i++)
        {
            if (i % 2 == 0){ a++; cout << a << " "; }
            else { b--; cout << b << " "; }
        }
        if (k % 2 == 0)
        {
            b--;
            while (a != b)
            {
                cout << b << " "; b--;
            }
            cout << endl;
        }
        else
        {
            a++;
            while (a != b)
            {
                cout << a << " "; a++;
            }
            cout << endl;
        }
    }
}