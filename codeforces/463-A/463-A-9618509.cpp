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
    int n, s;
    cin >> n >> s;
    float *a = new float[n];
    bool test = false;
    int min = 100;
    for (int i = 0; i < n; i++)
    {
        float x, y;
        cin >> x >> y;
        a[i] = x + (y / 100);
        if (s - a[i]>=0)
        {
            test = true;
            if (y <min&&y!=0)min = y;
        }
    }
    if (!test)cout << -1;
    else cout << 100-min;
}