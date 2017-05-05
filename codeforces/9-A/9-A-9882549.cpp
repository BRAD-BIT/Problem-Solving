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
#include<list>
#include <stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int x, y, z; cin >> x >> y; z = 6 - max(x, y) + 1;
    if (z == 6)cout << 1 << '/' << 1 << endl;
    else
    if (z == 5)cout << 5 << '/' << 6 << endl;
    else
    if (z == 4)cout << 2 << '/' << 3 << endl;
    else
    if (z == 3)cout << 1 << '/' << 2 << endl;
    else
    if (z == 2)cout << 1 << '/' << 3 << endl;
    else
    if (z == 1)cout << 1 << '/' << 6 << endl;
}