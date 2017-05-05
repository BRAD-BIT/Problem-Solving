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
    int n; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i];
    int height = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (height == 0){time += a[i] + 1;height += a[i];}
        else
        if (height>a[i]){time += (height - a[i]) + 2;height = a[i];}
        else
        if (height == a[i]){time += 2;}
        else 
        if (height < a[i]){time += (a[i] - height) + 2;height = a[i];}
    }
    cout << time << endl;
}