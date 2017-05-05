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
int main()
{
    int n;
    cin >> n;
    int sumZ = 0;
    int sumF = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 5)sumF++;
        else sumZ++;
    }
    int m = sumF / 9;
    if (m != 0 && sumZ != 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << 555555555;
        }
        for (int u = 0; u < sumZ; u++)
        {
            cout << 0;
        }
    }
    else
    if (sumZ != 0)cout << 0;
    else
        cout << -1;
}