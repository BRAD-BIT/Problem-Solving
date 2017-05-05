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
    int x, y; cin >> x >> y;
    int z = abs(x) + abs(y);
    if (x < 0)
    {
        if (y < 0)
        {
            cout << -z << " " << 0 << " " << 0 <<" "<< -z;
        }
        else
        {
            cout << -z << " " << 0 << " " << 0 << " "<<z;
        }
    }
    else
    {
        if (y < 0)
        {
            cout << 0 << " " << -z << " " << z << " " << 0;
        }
        else
        {
            cout << 0 << " " << z << " " << z << " " << 0;
        }
    }
}