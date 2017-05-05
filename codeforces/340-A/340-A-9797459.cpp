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
using namespace std;
int  lowestdivisible(int x, int y)
{
    int i = 1;
    while (i%x != 0 || i%y != 0)
    {
        i++;
    }
    return i;
}
int main()
{
    long long x, y, a, b; cin >> x >> y >> a >> b;
    cout << b / lowestdivisible(x, y) - (a-1) / lowestdivisible(x, y);
}