#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
struct point
{
    int x;
    int y;
};
int main()
{
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    if (a.x == b.x)cout << a.x + abs(a.y - b.y) << " " << a.y << " " << a.x + abs(a.y - b.y) << " " << b.y;
    else 
    if (a.y == b.y)cout << a.x << " " << a.y + abs(a.x - b.x) << " " << b.x << " " << a.y + abs(a.x - b.x);
    else
    if (abs(a.x - b.x) == abs(a.y - b.y))
    {
        if (a.x < b.x)cout << a.x + abs(a.x - b.x) << " " << a.y << " " << b.x - abs(a.x - b.x) << " " << b.y;
        else cout << a.x - abs(a.x - b.x) << " " << a.y << " " << b.x + abs(a.x - b.x) << " " << b.y;
    }
    else cout << -1;
}