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
    int a, b, c, d,x,y; cin >> a >> b >> c >> d;
    x = max((3 * a) / 10, a - (a / 250)*c); y = max((3 * b) / 10, b - (b / 250)*d);
    if (x > y)cout << "Misha"; if (x < y)cout << "Vasya"; if (x == y)cout << "Tie";
}