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
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int a[4]; cin >> a[0] >> a[1] >> a[2] >> a[3]; sort(a, a + 4);
    if (a[0] + a[1] > a[3] || a[1] + a[2] > a[3] || a[0] + a[1] > a[2] || a[0] + a[2] > a[3]){ cout << "TRIANGLE" << endl; return 0; }

    if (a[0] + a[1] == a[2] || a[0] + a[1] == a[3] || a[0] + a[2] == a[3] || a[1] + a[2] == a[3]){ cout << "SEGMENT " << endl; return 0; }
    { cout << "IMPOSSIBLE " << endl; return 0; }
}