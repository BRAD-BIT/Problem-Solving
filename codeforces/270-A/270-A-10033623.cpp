#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>  
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    float l = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l = 360.00 /float(180 - a[i]);
        if (l==ceil(l))
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}