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
    int n, m, k; cin >> n >> m >> k;
    int b[2015] = { 0 };
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c != '.')
            {
                if (c == 'R')if (i + j < m)b[i + j]++;
                if (c == 'L')if (j-i >= 0)b[j - i]++;
                if (c == 'U')if (i % 2 == 0)b[j]++;
            }
        }
    }
    for (int i = 0; i < m; i++)cout << b[i] << " "; cout << endl;
}