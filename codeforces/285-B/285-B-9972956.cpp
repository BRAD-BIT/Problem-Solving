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
    int n, s, t; cin >> n >> s >> t; int *a = new int[n];
    for (int i = 0; i < n; i++)cin >> a[i];
    int sum = 0;
    while (n != 0)
    {
        if (s == t){cout << sum << endl; return 0;}
        s = a[s - 1];
        sum++;
        n--;
    }
    cout << -1 << endl;
}