#include<iostream>
#include<string>
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
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int n, sum = 0; cin >> n; int a[5007]; for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        bool test = true;
        for (int j = 0; j < n; j++)if (a[j] == i + 1){ test = false; break; }
        if (test)sum++;
    }
    cout << sum << endl;
}