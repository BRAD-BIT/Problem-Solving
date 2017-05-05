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
    int n, m;
    cin >> n;
    long long *a = new long long[n];
    long long *b = new long long[n];
    long long *suma = new long long[n+1];
    long long *sumb = new long long[n+1];
    long long sumo = 0;
    suma[0] = 0;
    sumb[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        sumo = a[i] + sumo;
        suma[i+1] = sumo;
    }
    sumo = 0;
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        sumo += b[i];
        sumb[i+1] = sumo;
    }
    cin >> m;
    int x;
    int y;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        cin >> x;
        if (x == 1)
        {
            cin >> x >> y;
            cout << suma[y] - suma[x - 1] << endl;
        }
        else
        {
            cin >> x >> y;
            cout << sumb[y] - sumb[x - 1] << endl;
        }
    }
}