#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int z = n - b - 1;
    while (a > z)
    {
        z++;
    }
    cout<< n - z;
}