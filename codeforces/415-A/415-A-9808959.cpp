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
#include <stdio.h>
#include<fstream>
using namespace std; 
int main()
{
    int n, m, x; cin >> n >> m; int a[100] = { 0 };
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        for (int j = x - 1; j < n; j++)
        {
            if (a[j]!=0)break; else a[j] = x;
        }
    }
    for (int i = 0; i < n; i++)cout << a[i] << " ";
}