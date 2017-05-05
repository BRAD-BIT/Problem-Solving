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
    int n, v;
    cin >> n >> v;
    int *m = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        bool test = false;
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            long long b;
            cin >> b;
            if (b < v)test = true;
        }
        if (test)
        {
            sum++;
            m[i] = i+1;
        }
        else m[i] = 0;
    }
    cout << sum << endl;
    sort(m, m + n);
    for (int i = 0; i < n; i++)
    {
        if (m[i] != 0)cout << m[i] << " ";
    }
}