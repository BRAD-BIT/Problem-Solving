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
    int n;
    cin >> n;
    int z = (n*n);
    int j = 1;
    for (int i = 0; i <n ; i++)
    {
        int f = 0;
        while (f<n/2)
        {
            cout << j << " " << z - j + 1<<" ";
            j++;
            f++;
        }
        cout << endl;
    }
}